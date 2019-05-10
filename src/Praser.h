#ifndef _PRASER_H_
#define _PRASER_H_


#include "AST.h"
#include "AsmCode.h"

using namespace std;

class Praser {
public:

	Praser(AST*);	

	int varNum = 0; //��ʱ��������
	int tempNum = 0; ////��������
	int labelNum = 0; //��ǩ��
	vector<string> codeList; //�м����

	AsmCode asmcode; //x86�������ɶ���

	map<string, funcNode> funcPool;	//�����أ�������--> ������㣩
	map<string, string> labelPool;  //��ǩӳ���ϵ��ͳһ�ѱ�ǩӳ��Ϊlable_i����ʽ��
	vector<struct Block> blockStack;//ά���Ĵ����ջ

	struct AST* root;

	void praserInit();
	void praserAST(struct AST* node);

	
	void praser_declaration(struct AST* node);		//����praser_declaration�Ľڵ�
	void praser_init_declarator_list(string, struct AST*);
	void praser_init_declarator(string, struct AST* );			//����praser_init_declarator�Ľڵ�
	void praser_function_definition(struct AST*);
	void praser_parameter_list(struct AST*,string,bool);			//��ȡ�����β��б�
	void praser_parameter_declaration(struct AST*, string,bool);	//��ȡ���������β�
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


	struct varNode lookupNode(string name);	//���ر����ڵ�
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