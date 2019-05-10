#include "AST.h"
using namespace std;

string essential_type[]={ //这些类型的结点就算它的孩子只有一个（也就是说只有一条路可以走，仍然是不省略）
    "Program",//逗号一定要记得加
    "unary_operator",
    "assignment_expression",
    "assignment_operator",
    "init_declarator",
    "declaration" ,   
    "type_specifier",
    "storage_class_specifier",
    "struct_or_union",
    "type_qualifier",
    "direct_declarator",
    "pointer",
    "initializer",
    "statement" ,
    "block_item",
    "expression_statement",
    "translation_unit",
    "function_definition",
    "external_declaration",
    "parameter_list",
    "declaration_list",
    "init_declarator_list",
    "argument_expression_list",
    "primary_expression"
};

int essential_type_len=sizeof(essential_type)/sizeof(essential_type[0]);
int printtreestack[1000];


struct AST* new_node(string type, int num,...) { //以简便形式构建语法树
    
    /*  //打印全部结点 没必要
    printf("Line:%d\ttype:",yylineno);
    cout.setf(ios::left);
    cout.width(27);
    cout<<type<<"val:"<<yytext<<endl;
    */

   if(num==0){
       cout<<"get a token: " <<type <<endl;
   }

    va_list valist;//接收不定量参数 char* 指向当前参数的指针
    
    if(num == 1&& is_essential_type(type)!=1){// && is_essential_type(type)!=1
        struct AST* temp = NULL;
        
        va_start(valist,num);
        
        temp = va_arg(valist,struct AST*);
        
        return temp;
    }

    struct AST* head = new AST();
    struct AST* temp = NULL;
    head->left = NULL;
    head->right = NULL;
    head->text = "";
    head->type = type;
    va_start(valist,num);//使va_list指向起始的参数
    if(num > 0) { //不是叶子节点
        temp = va_arg(valist,struct AST*);//检索参数,第二个参数为数据类型，返回参数
        head->left = temp;//左孩子，
        head->line = temp->line;
        if(num == 1) { //只有一个参数，直接赋值
            head->text = temp->text;

        }
        else { //有多个参数，用右兄弟表示
            for(int i = 1; i < num; ++i ) {
                temp->right = va_arg(valist,struct AST*);
                temp = temp->right;
            }
        }
    }
    else {    //叶子结点
        int line = va_arg(valist,int);
        head->line = line;
        if(head->type == "CONSTANT_INT") {
           int value;
           if(strlen(yytext) > 1 && yytext[0] == '0' && yytext[1] != 'x') {
               sscanf(yytext,"%o",&value); //8进制整数
           }
           else if(strlen(yytext) > 1 && yytext[1] == 'x'){
               sscanf(yytext,"%x",&value); //16进制整数
           }
           else {
               value = atoi(yytext);      //10进制整数
           }
           
           head->text = inttostr(value);

        }
        else { //直接赋值
            head->text = yytext;
        }
    }
    return head;
}



void print_AST(AST *head,int leavel) {
    if(head!=NULL) {
        string type = head->type;

        for(int i=0;i<leavel;++i) {
            if(printtreestack[i]==0){
                cout<<"  ";
            }else{
                cout<<"| ";
            }
        }
        cout<<"+-" << head->type;

        //有真实值的类型 
        if(head->type == "IDENTIFIER"||head->type == "CONSTANT_INT" || head->type == "CONSTANT_DOUBLE" || head->type == "STRING_LITERAL") {
            cout << " :" << head->text;
        }
        
        cout << endl;

        if(head->right!=NULL){
            printtreestack[leavel]=1;
        }

        print_AST(head->left,leavel+1);
        printtreestack[leavel]=0; //将高位的1归零,很关键

        print_AST(head->right,leavel);
    }
}


int is_essential_type(string str){
    int i=0;
    int is_essential_type=0;
    for(i=0;i<essential_type_len;i++){
        if(essential_type[i]==str){
            is_essential_type=1;
            break;
        }
    }
    return is_essential_type;
}


string inttostr(int n) {
	char buf[10];
	sprintf(buf, "%d", n);
	string b = buf;
	return b;
}

int strtoint(string s) {
	int n;
	n = atoi(s.c_str());
	return n;
}
