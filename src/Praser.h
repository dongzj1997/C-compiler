#ifndef _PRASER_H_
#define _PRASER_H_


#include "AST.h"
#include "AsmCode.h"

using namespace std;

class Praser {
public:

	Praser(AST*);	

	int varNum = 0; //临时变量个数
	int tempNum = 0; ////变量个数
	int labelNum = 0; //标签号
	vector<string> codeList; //中间代码

	AsmCode asmcode; //x86代码生成对象

	map<string, funcNode> funcPool;	//函数池（函数名--> 函数结点）
	map<string, string> labelPool;  //标签映射关系（统一把标签映射为lable_i的形式）
	vector<struct Block> blockStack;//维护的代码块栈

	struct AST* root;

	void praserInit();
	void praserAST(struct AST* node);

	
	void praser_declaration(struct AST* node);		//分析praser_declaration的节点
	void praser_init_declarator_list(string, struct AST*);
	void praser_init_declarator(string, struct AST* );			//分析praser_init_declarator的节点
	void praser_function_definition(struct AST*);
	void praser_parameter_list(struct AST*,string,bool);			//获取函数形参列表
	void praser_parameter_declaration(struct AST*, string,bool);	//获取函数单个形参
	void praser_statement(struct AST*);

	void praser_expression_statement(struct AST*);
	void praser_argument_expression_list(struct AST*,string);

	void praser_labeled_statement(struct AST*);
	void praser_jump_statement(struct AST*);
	void praser_compound_statement(struct AST*);
	void praser_selection_statement(struct AST*);
	void praser_iteration_statement(struct AST*);

	varNode praser_expression(struct AST*);
	varNode praser_assignment_expression(struct AST*);	
	varNode praser_logical_or_expression(struct AST*);	
	varNode praser_logical_and_expression(struct AST*);	
	varNode praser_equality_expression(struct AST*);
	varNode praser_relational_expression(struct AST*);
	varNode praser_additive_expression(struct AST*);
	varNode praser_multiplicative_expression(struct AST*);
	varNode praser_postfix_expression(struct AST*);
	varNode praser_primary_expression(struct AST*);


	struct varNode lookupNode(string name);	//返回变量节点
	string getFuncRType();
	string getLabelName();
	string getNodeName(varNode node);
	string Gen_IR(string tempname, string op, varNode node1, varNode node2);
	struct varNode createTempVar(string name, string type);
	void addCode(string);
	void print_code();
	void error(int line, string error);


};

#endif 