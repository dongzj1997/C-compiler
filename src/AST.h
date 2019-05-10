#ifndef _TREE_H_

#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

extern char *yytext;
extern int yylineno;

struct AST {
    int line;       //结点在源文件中的位置
    string text;    //结点的内容，即原始字符串，一般为空，除非为叶节点
    string type;    //结点的类型，为flex返回值（叶节点）,或者归约值
    struct AST *left;
    struct AST *right;
};

struct varNode { //变量结点
	string name;
	string type;
	int num = -1;
};


struct funcNode {//函数节点
	bool isdefinied = false;  //是否已经被定义
	string name;				//函数名
	string rtype;				//函数返回类型
	vector<varNode> paralist;	//记录形参列表
};




struct Block { //独立的代码段，有独立的命名空间
	funcNode func;
	bool isfunc = false;                //记录是否是函数
	map<string, struct varNode> varMap;	//变量的map
	string breakLabelname=""; //块的break位置
	string continueLabelname="";
};


extern struct AST *root;

struct AST* new_node(string type, int num,...);
void print_AST(struct AST *head,int leavel);
int is_essential_type(string str);
string inttostr(int n);
int strtoint(string s);

#endif