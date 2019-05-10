#ifndef _ASMCODE_H_
#define _ASMCODE_H_

#include "AST.h"

using namespace std;

class AsmCode {
public:
    
    string funcname="";
	vector<string> AsmCodeList;
    map<string, string> varMap;//存储变量和x86虚拟机内存的对应情况
    map<string, string> JMPTable;//选择跳转指令时的查找表
    
    int point=0;//内存指针
    int param_num=0;//参数个数
    int param_num_in=0;//传入参数个数
    string CMPflag="";//记录上一次比较的操作，用于跳转
    AsmCode();


    void addCode(string str);
    void printCode();
    void CodeGen(vector<string> CodeList);
    string dectohex(int a );
    string new_mem(string var);
};

#endif // !_ASMCODE_H_
