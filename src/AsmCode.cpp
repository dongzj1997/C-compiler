//���룺GB2312
#include "AsmCode.h"
using namespace std;

AsmCode::AsmCode( ) {
}


void AsmCode::addCode(string str) {
    //cout<<str<<endl;
	AsmCodeList.push_back(str);
}

void AsmCode::printCode() {

	for (string s : AsmCodeList) {
		cout << s << endl;
	}
}


void AsmCode::CodeGen(vector<string> CodeList){ //CodeList ָ�м����

    //��ʼ����ת���ұ�
    JMPTable.insert({">","JG"}); //�з��Ŵ�������ת���޷���λJA��
    JMPTable.insert({">=","JGE"});//�з��Ŵ��ڵ�������ת
    JMPTable.insert({"<","JL"});//�޷���λJB
    JMPTable.insert({"<=","JLE"});
    JMPTable.insert({"==","JE"});
    JMPTable.insert({"!=","JNE"});

    JMPTable.insert({"N>","JLE"}); // ��һ��N��ʾ���� IF ������ ==FALSE �����
    JMPTable.insert({"N>=","JL"});
    JMPTable.insert({"N<","JGE"});
    JMPTable.insert({"N<=","JG"});
    JMPTable.insert({"N==","JNE"});
    JMPTable.insert({"N!=","JE"});

    addCode("include 'emu8086.inc'");
    addCode("ORG 100h");
    addCode("MOV AX,0500H");
    addCode("MOV DS,AX"); //��ʼ�����ݶ��׵�ַ
    addCode("CALL MAIN");
    addCode(".EXIT");
    addCode("");



	for (string s : CodeList) {
		if (s.find("FUNC") == 0)//����
		{
            param_num_in=0;//����������ĸ�������Ϊ0
            int len=s.length();
            //string substr(int pos = 0,int n = npos) const;
            //����pos��ʼ��n���ַ���ɵ��ַ���
            funcname=s.substr(5,len-6);
            
            addCode("");
			addCode(funcname+" PROC");
            if(funcname!="main"){
                addCode("MOV DX,DS");
                addCode("ADD DX,0010h");
                addCode("MOV DS,DX");
            }
            continue;
		}
        else if(s.find("RETURN") == 0){ //������� ����ɣ�����Լ���������ķ���ֵ�浽CX�� todo
            if(s.length()>6){//˵���з���ֵ
                string return_name=s.substr(7);
                addCode("MOV CX,"+varMap[return_name]);
            }
            if(funcname!="main"){
                addCode("MOV DX,DS");
                addCode("SUB DX,0010h");
                addCode("MOV DS,DX");
            }
            addCode("RET");
            addCode(funcname+" ENDP");
            continue;
        }
        else if(s.find("label") == 0){ //��ǩ���
            // int len=s.length();
            // string labelname=s.substr(6,len-6);
            addCode(s);
        }
        else if(s.find("IF") == 0){ //��ǩ���
            string t=CMPflag; //����Ϊ�˷�ֹ�ı�CMPflag��ֵ ʹ��һ����ʱ����
            if(s.find("FALSE")!=s.npos){
                t="N"+t;
            }
            int label_pos=s.find("GOTO") +5;
            string labelname=s.substr(label_pos);
            addCode(JMPTable[t]+" "+labelname);
            continue;
        }
        else if(s.find("GOTO") == 0){ //��ǩ���
            string dist=s.substr(5);
            addCode("JMP "+dist);
            
        }
        else if(s.find("PARAM_PREP") == 0){ //����׼��
            if(param_num>=4){
                //todo  ��ʣ��Ĳ���ʹ��ջ�������ڴ�������
                cout<<"TODO ������������"<<endl;
            }
            string param_name=s.substr(11);
            string param_reg[4]={"AX","BX","CX","DX"};//�����������Ĵ�����λ��
            addCode("MOV "+param_reg[param_num]+","+varMap[param_name]);
            param_num++;
        }
        else if(s.find("PARAM_IN") == 0){ //����׼��
            if(param_num_in>=4){
                //todo  ��ʣ��Ĳ���ʹ��ջ�������ڴ�������
                cout<<"TODO ������������"<<endl;
            }
            string var1=s.substr(9);
            string mem1;
            string param_reg[4]={"AX","BX","CX","DX"};//�����������Ĵ�����λ��

            if(varMap.find(var1) !=varMap.end()){
                mem1=varMap[var1];
            }else{
                mem1=new_mem(var1);
            } 

            addCode("MOV "+mem1+","+param_reg[param_num_in]);
            param_num_in++;
        }
        else if(s.find("CALL") == 0){ //�������ã�һ����û�з���ֵ�ĵĺ���
            //callָ����ȱ���eip��ֵ��ջ���棨esp����Ȼ�����ת��Ŀ�꺯����ȥ�ˡ�
            //ջ�ǳ��ŵ͵�ַ�ķ����쳤��,��ջ��Ҫ�ü���
            param_num=0;//��������������
            string callfuncname=s.substr(5);
            if(callfuncname=="print"){ //���Կ��Ǻϲ�
                addCode("CALL print_num");//; get number in CX.
            }
            else{
                //������������
                addCode("CALL "+callfuncname);
            }
        }
        else { //��ֵ���  ...=...
            string var1;
            string var2;
            string var3;
            string mem1;
            string mem2;
            string mem3;    
            int op_pos1=s.find("=");

            var1=s.substr(0,op_pos1-1); //= ��֮ǰ�ı�����
            
            int flag=0;
            int op_pos2;
            
    
            if(s.find("+")!=s.npos ||s.find("-")!=s.npos||s.find("*")!=s.npos||s.find("/")!=s.npos){
                flag=1; //��ʾ��ͨ�Ӽ��˳�����
            }

            if(s.find(">")!=s.npos ||s.find("<")!=s.npos){
                flag=2; //��ʾ���ڻ�С�� ����
                
            }
            
            //ע������ĻὫ���� �ĸ��� ����һ��feature
            if(s.find(">=")!=s.npos ||s.find("<=")!=s.npos||s.find("==")!=s.npos ||s.find("!=")!=s.npos){
                flag=3; //��ʾ�����ַ���  ���ڵ���  �� С�ڵ��� ��== ��!=����
            }



            char ch[6]={'+','-','*','/','>','<'};
            for (int i=0;i<6;i++){
                if(s.find(ch[i])!=s.npos){
                    
                    op_pos2=s.find(ch[i]);
                    break;
                }
            } 

            if(s.find("==")!=s.npos){
                op_pos2=s.find("==");
            }
            if(s.find("!=")!=s.npos){
                op_pos2=s.find("!=");
            }



            // map<string, string> varMap;
            if(flag==1){
                var2=s.substr(op_pos1+2,op_pos2-op_pos1-3);
                var3=s.substr(op_pos2+2);
                //cout<<var1 << var2<< var3<<endl;
                mem2=varMap[var2];
                mem3=varMap[var3];
                addCode("MOV AX,"+mem2);
                addCode("MOV BX,"+mem3);

                if(s[op_pos2]=='+'){
                    addCode("ADD AX,BX");
                }else if(s[op_pos2]=='-'){
                    addCode("SUB AX,BX");
                }else if(s[op_pos2]=='*'){
                    addCode("IMUL BL");
                }else if(s[op_pos2]=='/'){
                    addCode("IDIV BL");
                }
                
                if(varMap.find(var1) !=varMap.end()){
                    mem1=varMap[var1];
                }else{
                    mem1=new_mem(var1);
                } 
                addCode("MOV "+mem1+",AX");
            }
            else if(flag==2){
                var2=s.substr(op_pos1+2,op_pos2-op_pos1-3);
                var3=s.substr(op_pos2+2);
                //cout<<var1 << var2<< var3<<endl;
                mem2=varMap[var2];
                mem3=varMap[var3];
                addCode("MOV AX,"+mem2);
                addCode("MOV BX,"+mem3);
                addCode("SUB AX,BX");  //todo ��ϸ��ע��

                if(s[op_pos2]=='<'){
                   CMPflag="<";
                }else if(s[op_pos2]=='>'){
                    CMPflag=">";
                }

                if(varMap.find(var1) !=varMap.end()){
                    mem1=varMap[var1];
                }else{
                    mem1=new_mem(var1);
                } 
                addCode("MOV "+mem1+",AX");

            }
            else if(flag==3){
                var2=s.substr(op_pos1+2,op_pos2-op_pos1-3);
                var3=s.substr(op_pos2+3);
                //cout<<var1 << var2<< var3<<endl;
                mem2=varMap[var2];
                mem3=varMap[var3];
                addCode("MOV AX,"+mem2);
                addCode("MOV BX,"+mem3);
                addCode("SUB AX,BX");  //todo ��ϸ��ע��

                if(s[op_pos2]=='<'){
                   CMPflag="<=";
                }else if(s[op_pos2]=='>'){
                    CMPflag=">=";
                }else if(s[op_pos2]=='!'){
                    CMPflag="!=";
                }else if(s[op_pos2]=='='){
                    CMPflag="==";
                }

                
                if(varMap.find(var1) !=varMap.end()){
                    mem1=varMap[var1];
                }else{
                    mem1=new_mem(var1);
                } 
                addCode("MOV "+mem1+",AX");

            }            
            else{  //��������ֵ  �������з���ֵ�ĺ�������
                var2=s.substr(op_pos1+2);
                if(var2.find("CALL") == 0){
                    //��������
                    param_num=0;//��������������
                    string callfuncname=var2.substr(5);
                    if(callfuncname=="scan"){ //���Կ��Ǻϲ�
                        addCode("CALL scan_num");//; get number in CX.
                    }
                    else{
                        //������������
                        addCode("CALL "+callfuncname);
                    }

                    if(varMap.find(var1) !=varMap.end()){
                        mem1=varMap[var1];
                    }else{
                        mem1=new_mem(var1);
                    }  
                    addCode("MOV "+mem1+",CX"); //Լ���������ķ���ֵ�浽CX��
                }
                else{//��������ֵ
                    if(isdigit(var2[0])){
                        addCode("MOV AX,"+var2);
                    }
                    else{
                        addCode("MOV AX,"+varMap[var2]);
                    }
                    

                    if(varMap.find(var1) !=varMap.end()){
                        mem1=varMap[var1];
                    }else{
                        mem1=new_mem(var1);
                    }   
                    
                    addCode("MOV "+mem1+",AX");
                }


            }

        }
	}


    addCode("DEFINE_SCAN_NUM");
    addCode("DEFINE_PRINT_NUM");
    addCode("DEFINE_PRINT_NUM_UNS   ");
    addCode("END");
}

string AsmCode::new_mem(string var)
{
    string mem="["+dectohex(point)+"]";
    varMap.insert({var,mem});
    point+=2;
    return mem;
}

string AsmCode::dectohex(int a )
{
    char str[100]; 
    itoa(a, str, 16);  
    strupr(str);
    string s = str;
    
    if(a<16){
        return "0"+s+"H";
    }
    else{
        return s+"H";
    }
}