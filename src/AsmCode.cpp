//编码：GB2312
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


void AsmCode::CodeGen(vector<string> CodeList){ //CodeList 指中间代码

    //初始化跳转查找表
    JMPTable.insert({">","JG"}); //有符号大于则跳转（无符号位JA）
    JMPTable.insert({">=","JGE"});//有符号大于等于则跳转
    JMPTable.insert({"<","JL"});//无符号位JB
    JMPTable.insert({"<=","JLE"});
    JMPTable.insert({"==","JE"});
    JMPTable.insert({"!=","JNE"});

    JMPTable.insert({"N>","JLE"}); // 加一个N表示处理 IF 。。。 ==FALSE 的情况
    JMPTable.insert({"N>=","JL"});
    JMPTable.insert({"N<","JGE"});
    JMPTable.insert({"N<=","JG"});
    JMPTable.insert({"N==","JNE"});
    JMPTable.insert({"N!=","JE"});

    addCode("include 'emu8086.inc'");
    addCode("ORG 100h");
    addCode("MOV AX,0500H");
    addCode("MOV DS,AX"); //初始化数据段首地址
    addCode("CALL MAIN");
    addCode(".EXIT");
    addCode("");



	for (string s : CodeList) {
		if (s.find("FUNC") == 0)//函数
		{
            param_num_in=0;//将传入参数的个数重置为0
            int len=s.length();
            //string substr(int pos = 0,int n = npos) const;
            //返回pos开始的n个字符组成的字符串
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
        else if(s.find("RETURN") == 0){ //返回语句 待完成！！！约定：函数的返回值存到CX中 todo
            if(s.length()>6){//说明有返回值
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
        else if(s.find("label") == 0){ //标签语句
            // int len=s.length();
            // string labelname=s.substr(6,len-6);
            addCode(s);
        }
        else if(s.find("IF") == 0){ //标签语句
            string t=CMPflag; //这里为了防止改变CMPflag的值 使用一个临时变量
            if(s.find("FALSE")!=s.npos){
                t="N"+t;
            }
            int label_pos=s.find("GOTO") +5;
            string labelname=s.substr(label_pos);
            addCode(JMPTable[t]+" "+labelname);
            continue;
        }
        else if(s.find("GOTO") == 0){ //标签语句
            string dist=s.substr(5);
            addCode("JMP "+dist);
            
        }
        else if(s.find("PARAM_PREP") == 0){ //参数准备
            if(param_num>=4){
                //todo  将剩余的参数使用栈或者是内存来传输
                cout<<"TODO 大量参数传递"<<endl;
            }
            string param_name=s.substr(11);
            string param_reg[4]={"AX","BX","CX","DX"};//传入参数放入寄存器的位置
            addCode("MOV "+param_reg[param_num]+","+varMap[param_name]);
            param_num++;
        }
        else if(s.find("PARAM_IN") == 0){ //参数准备
            if(param_num_in>=4){
                //todo  将剩余的参数使用栈或者是内存来传输
                cout<<"TODO 大量参数传递"<<endl;
            }
            string var1=s.substr(9);
            string mem1;
            string param_reg[4]={"AX","BX","CX","DX"};//传入参数放入寄存器的位置

            if(varMap.find(var1) !=varMap.end()){
                mem1=varMap[var1];
            }else{
                mem1=new_mem(var1);
            } 

            addCode("MOV "+mem1+","+param_reg[param_num_in]);
            param_num_in++;
        }
        else if(s.find("CALL") == 0){ //函数调用，一般是没有返回值的的函数
            //call指令会先保存eip的值到栈里面（esp），然后就跳转到目标函数中去了。
            //栈是朝着低地址的方向伸长的,入栈需要用减法
            param_num=0;//将参数个数清零
            string callfuncname=s.substr(5);
            if(callfuncname=="print"){ //可以考虑合并
                addCode("CALL print_num");//; get number in CX.
            }
            else{
                //其他函数调用
                addCode("CALL "+callfuncname);
            }
        }
        else { //赋值语句  ...=...
            string var1;
            string var2;
            string var3;
            string mem1;
            string mem2;
            string mem3;    
            int op_pos1=s.find("=");

            var1=s.substr(0,op_pos1-1); //= 号之前的变量名
            
            int flag=0;
            int op_pos2;
            
    
            if(s.find("+")!=s.npos ||s.find("-")!=s.npos||s.find("*")!=s.npos||s.find("/")!=s.npos){
                flag=1; //表示普通加减乘除运算
            }

            if(s.find(">")!=s.npos ||s.find("<")!=s.npos){
                flag=2; //表示大于或小于 运算
                
            }
            
            //注意下面的会将上面 的覆盖 这是一个feature
            if(s.find(">=")!=s.npos ||s.find("<=")!=s.npos||s.find("==")!=s.npos ||s.find("!=")!=s.npos){
                flag=3; //表示两个字符的  大于等于  或 小于等于 或== 或!=运算
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
                addCode("SUB AX,BX");  //todo 详细的注释

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
                addCode("SUB AX,BX");  //todo 详细的注释

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
            else{  //立即数赋值  或者是有返回值的函数调用
                var2=s.substr(op_pos1+2);
                if(var2.find("CALL") == 0){
                    //函数调用
                    param_num=0;//将参数个数清零
                    string callfuncname=var2.substr(5);
                    if(callfuncname=="scan"){ //可以考虑合并
                        addCode("CALL scan_num");//; get number in CX.
                    }
                    else{
                        //其他函数调用
                        addCode("CALL "+callfuncname);
                    }

                    if(varMap.find(var1) !=varMap.end()){
                        mem1=varMap[var1];
                    }else{
                        mem1=new_mem(var1);
                    }  
                    addCode("MOV "+mem1+",CX"); //约定，函数的返回值存到CX中
                }
                else{//立即数赋值
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