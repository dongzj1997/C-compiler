%{
/* code : GB2312
* 基于bison的c语言语法分析器
* 用于语法检查和制导生成抽象语法树
* 作者：dongzj1997
* 参考：http://www.quut.com/c/ANSI-C-grammar-y-1995.html
* 具体每种短语代表的含义以及他们的关系，请查看 .\compiler.vsdx （Visio格式）
*/
#include "AST.h"
#include "Praser.h"


extern char *yytext;
extern FILE * yyin;
extern int yylineno;
struct AST *root;

int yylex(void);
void yyerror(const char*); 

%}


%union{
	struct AST* node;
}

%token <node> IDENTIFIER CONSTANT STRING_LITERAL SIZEOF CONSTANT_INT CONSTANT_DOUBLE 
%token <node> PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token <node> AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token <node> SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token <node> XOR_ASSIGN OR_ASSIGN TYPE_NAME
%token <node> CHAR INT DOUBLE VOID  FLOAT
%token <node> AUTO CONST DEFAULT ENUM EXTERN INLINE LONG REGISTER SHORT SIGNED STATIC TYPEDEF UNION STRUCT UNSIGNED ELLIPSIS
%token <node> VOLATILE
%token <node> CASE IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
%token <node> ';' ',' ':' '=' '[' ']' '.' '&' '!' '~' '-' '+' '*' '/' '%' '<' '>' '^' '|' '?' '{' '}' '(' ')'

%type  <node> primary_expression postfix_expression argument_expression_list unary_expression unary_operator
%type  <node> multiplicative_expression additive_expression shift_expression relational_expression equality_expression
%type  <node> and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression
%type  <node> assignment_expression assignment_operator expression
%type  <node> declaration init_declarator_list init_declarator type_specifier
%type  <node> declarator 
%type  <node> parameter_list parameter_declaration identifier_list
%type  <node> abstract_declarator initializer initializer_list  
%type  <node> statement labeled_statement compound_statement block_item_list block_item expression_statement
%type  <node> selection_statement iteration_statement jump_statement translation_unit external_declaration function_definition
%type  <node> declaration_list
%type  <node> type_name cast_expression conditional_expression declaration_specifiers  constant_expression storage_class_specifier
%type  <node> struct_or_union_specifier  enum_specifier type_qualifier struct_declaration_list struct_declaration struct_declarator
%type  <node> struct_or_union enumerator_list specifier_qualifier_list struct_declarator_list enumerator
%type  <node> pointer direct_declarator direct_abstract_declarator

%nonassoc THE_FIRST_IF_IN_FRONT
%nonassoc ELSE

%start Program

%%
Program: 
	translation_unit {
		root = new_node("Program",1,$1);
	}
	;

primary_expression: 
	IDENTIFIER {
		$$ = new_node("primary_expression",1,$1);
	}
	| CONSTANT_INT {
		$$ = new_node("primary_expression",1,$1);	
	}
	| CONSTANT_DOUBLE {
		$$ = new_node("primary_expression",1,$1);
	}
	| STRING_LITERAL {
		$$ = new_node("primary_expression",1,$1);
	}
	| '(' expression ')'{
		$$ = new_node("primary_expression",3,$1,$2,$3);
	}
	;

postfix_expression:
	primary_expression{
		$$ = new_node("postfix_expression",1,$1);
	}
	| 	postfix_expression '[' expression ']'{
		$$ = new_node("postfix_expression",4,$1,$2,$3,$4);
	}
	| 	postfix_expression '(' ')'{
		$$ = new_node("postfix_expression",3,$1,$2,$3);
		//函数调用,不带参数
	}
	| 	postfix_expression '(' argument_expression_list ')'{
		$$ = new_node("postfix_expression",4,$1,$2,$3,$4);
		//函数调用，带参数
	}
	| 	postfix_expression '.' IDENTIFIER{
		$$ = new_node("postfix_expression",3,$1,$2,$3);
	}
	| 	postfix_expression PTR_OP IDENTIFIER{
		//a->b
		$$ = new_node("postfix_expression",3,$1,$2,$3);
	}
	| 	postfix_expression INC_OP{
		$$ = new_node("postfix_expression",2,$1,$2);
		//i++
	}
	| 	postfix_expression DEC_OP{
		$$ = new_node("postfix_expression",2,$1,$2);
		//i--
	}
	;

argument_expression_list:
	assignment_expression{
		$$ = new_node("argument_expression_list",1,$1);
	}
	| 	argument_expression_list ',' assignment_expression {
		$$ = new_node("argument_expression_list",3,$1,$2,$3);
	}
	;

unary_expression:
	postfix_expression{
		$$ = new_node("unary_expression",1,$1);
	}
	| 	INC_OP unary_expression{
		$$ = new_node("unary_expression",2,$1,$2);
		//++i
	}
	| 	DEC_OP unary_expression{
		$$ = new_node("unary_expression",2,$1,$2);
		//--i
	}
	| 	unary_operator cast_expression{
		$$ = new_node("unary_expression",2,$1,$2);
	}
	| 	SIZEOF unary_expression{
		$$ = new_node("unary_expression",2,$1,$2);
	}
	| 	SIZEOF '(' type_name ')'{
		$$ = new_node("unary_expression",4,$1,$2,$3,$4);
	}
	;

unary_operator:
	
	'&' {
		$$ = new_node("unary_operator",1,$1);
	}
	| '*' {
		$$ = new_node("unary_operator",1,$1);
	}
	| '+' {
		$$ = new_node("unary_operator",1,$1);
	}
	| '-' {
		$$ = new_node("unary_operator",1,$1);
	}
	| '~' {
		$$ = new_node("unary_operator",1,$1);
	}
	| '!' {
		$$ = new_node("unary_operator",1,$1);
	}
	;

cast_expression:
    unary_expression{
		$$ = new_node("cast_expression",1,$1);
	}
	| '(' type_name ')' cast_expression{
		$$ = new_node("cast_expression",4,$1,$2,$3,$4);
	}
	;

multiplicative_expression:
	cast_expression {
		$$ = new_node("multiplicative_expression",1,$1);
	}
	| multiplicative_expression '*' cast_expression {
		$$ = new_node("multiplicative_expression",3,$1,$2,$3);
	}
	| multiplicative_expression '/' cast_expression {
		$$ = new_node("multiplicative_expression",3,$1,$2,$3);
	}
	| multiplicative_expression '%' cast_expression {
		$$ = new_node("multiplicative_expression",3,$1,$2,$3);
	}
	;

additive_expression:
	multiplicative_expression  {
		$$ = new_node("additive_expression",1,$1);
	}
	| additive_expression '+' multiplicative_expression {
		$$ = new_node("additive_expression",3,$1,$2,$3);
	}
	| additive_expression '-' multiplicative_expression {
		$$ = new_node("additive_expression",3,$1,$2,$3);
	}
	;

shift_expression:
	additive_expression {
		$$ = new_node("shift_expression",1,$1);
	}
	| shift_expression LEFT_OP additive_expression {
		$$ = new_node("shift_expression",3,$1,$2,$3);
		// 左移<<
	}
	| shift_expression RIGHT_OP additive_expression {
		$$ = new_node("shift_expression",3,$1,$2,$3);
		// <<右移
	}
	;

relational_expression:
	shift_expression {
		$$ = new_node("relational_expression",1,$1);
	}
	| relational_expression '<' shift_expression {
		$$ = new_node("relational_expression",3,$1,$2,$3);
	}
	| relational_expression '>' shift_expression {
		$$ = new_node("relational_expression",3,$1,$2,$3);
	}
	| relational_expression LE_OP shift_expression {
		$$ = new_node("relational_expression",3,$1,$2,$3);
		// <= 
	}
	| relational_expression GE_OP shift_expression {
		$$ = new_node("relational_expression",3,$1,$2,$3);
		// >=
	}
	;

equality_expression:
	relational_expression {
		$$ = new_node("equality_expression",1,$1);
	}
	| equality_expression EQ_OP relational_expression {
		$$ = new_node("equality_expression",3,$1,$2,$3);
		// ==
	}
	| equality_expression NE_OP relational_expression {
		$$ = new_node("equality_expression",3,$1,$2,$3);
		// !=
	}
	;

and_expression:
	equality_expression {
		$$ = new_node("and_expression",1,$1);
	}
	| and_expression '&' equality_expression {
		$$ = new_node("and_expression",3,$1,$2,$3);
	}
	;

exclusive_or_expression:
	and_expression {
		$$ = new_node("exclusive_or_expression",1,$1);
	}
	| exclusive_or_expression '^' and_expression {
		$$ = new_node("exclusive_or_expression",3,$1,$2,$3);
		//异或表达式
	}
	;

inclusive_or_expression:
	exclusive_or_expression {
		$$ = new_node("inclusive_or_expression",1,$1);
	}
	| inclusive_or_expression '|' exclusive_or_expression {
		$$ = new_node("inclusive_or_expression",3,$1,$2,$3);
	}
	;

logical_and_expression:
	inclusive_or_expression {
		$$ = new_node("logical_and_expression",1,$1);
	}
	| logical_and_expression AND_OP inclusive_or_expression {
		$$ = new_node("logical_and_expression",3,$1,$2,$3);
	}
	;

logical_or_expression:
	logical_and_expression {
		$$ = new_node("logical_or_expression",1,$1);
	}
	| logical_or_expression OR_OP logical_and_expression {
		$$ = new_node("logical_or_expression",3,$1,$2,$3);
	}
	;

conditional_expression:
    logical_or_expression{
		$$ = new_node("conditional_expression",1,$1);
	}
	| logical_or_expression '?' expression ':' conditional_expression{
		$$ = new_node("conditional_expression",5,$1,$2,$3,$4,$5);
		//C语言唯一一个三目运算符
	}
	;

assignment_expression:
	conditional_expression {
		$$ = new_node("assignment_expression",1,$1);
	}
	| unary_expression assignment_operator assignment_expression {
		$$ = new_node("assignment_expression",3,$1,$2,$3);
	}
	;

assignment_operator:
	'=' {
		$$ = new_node("assignment_operator",1,$1);
	}
	| MUL_ASSIGN {
		//*=
		$$ = new_node("assignment_operator",1,$1);
	}
	| DIV_ASSIGN {
		// /=
		$$ = new_node("assignment_operator",1,$1);
	}
	| MOD_ASSIGN {
		// %=
		$$ = new_node("assignment_operator",1,$1);
	}
	| ADD_ASSIGN {
		// += 
		$$ = new_node("assignment_operator",1,$1);
	}
	| SUB_ASSIGN {
		// -=
		$$ = new_node("assignment_operator",1,$1);
	}
	| LEFT_ASSIGN {
		// <<=
		$$ = new_node("assignment_operator",1,$1);
	}
	| RIGHT_ASSIGN {
		// >>=
		$$ = new_node("assignment_operator",1,$1);
	}
	| AND_ASSIGN {
		// &=
		$$ = new_node("assignment_operator",1,$1);
	}
	| XOR_ASSIGN {
		// ^=
		$$ = new_node("assignment_operator",1,$1);
	}
	| OR_ASSIGN {
		// |=
		$$ = new_node("assignment_operator",1,$1);
	}
	;

expression:
	assignment_expression {
		$$ = new_node("expression",1,$1);
	}
	| expression ',' assignment_expression {
		$$ = new_node("expression",3,$1,$2,$3);
	}
	;

constant_expression:
    conditional_expression{
		$$ = new_node("constant_expression",1,$1);
		//常量表达式-->条件表达式
	}
	;

declaration:
	declaration_specifiers ';' {
		$$ = new_node("declaration",2,$1,$2); 
		// int; 在C语言中是合法的
	}
	| declaration_specifiers init_declarator_list ';' {
		$$ = new_node("declaration",3,$1,$2,$3);
	}
	;

declaration_specifiers:
    storage_class_specifier{
		$$ = new_node("declaration_specifiers",1,$1);
	}
	| storage_class_specifier declaration_specifiers{
		$$ = new_node("declaration_specifiers",2,$1,$2); 
	}
	| type_specifier{
		$$ = new_node("declaration_specifiers",1,$1);
	}
	| type_specifier declaration_specifiers{
		$$ = new_node("declaration_specifiers",2,$1,$2); 
	}
	| type_qualifier{
		$$ = new_node("declaration_specifiers",1,$1);
	}
	| type_qualifier declaration_specifiers{
		$$ = new_node("declaration_specifiers",2,$1,$2); 
	}
	;

init_declarator_list:
	init_declarator {
		$$ = new_node("init_declarator_list",1,$1);
	}
	| init_declarator_list ',' init_declarator {
		$$ = new_node("init_declarator_list",3,$1,$2,$3);
	}
	;

init_declarator:
	declarator {
		$$ = new_node("init_declarator",1,$1);
	}
	| declarator '=' initializer {
		$$ = new_node("init_declarator",3,$1,$2,$3);
	}
	;

storage_class_specifier:
    TYPEDEF{
		$$ = new_node("storage_class_specifier",1,$1);
	}
	| EXTERN{
		$$ = new_node("storage_class_specifier",1,$1);
	}
	| STATIC{
		$$ = new_node("storage_class_specifier",1,$1);
	}
	| AUTO{
		$$ = new_node("storage_class_specifier",1,$1);
	}
	| REGISTER{
		$$ = new_node("storage_class_specifier",1,$1);
	}
	;

type_specifier:
	VOID {
		$$ = new_node("type_specifier",1,$1);
	}
	| CHAR {
		$$ = new_node("type_specifier",1,$1);
	}
	| INT {
		$$ = new_node("type_specifier",1,$1);
	}
	| DOUBLE {
		$$ = new_node("type_specifier",1,$1);	
	}
	| SIGNED {
		$$ = new_node("type_specifier",1,$1);
	}
	| struct_or_union_specifier{
		$$ = new_node("type_specifier",1,$1);
		//结构体
	}
	| enum_specifier{
		$$ = new_node("type_specifier",1,$1);
	}
	| TYPE_NAME{
		$$ = new_node("type_specifier",1,$1);
	}
	;

struct_or_union_specifier:
    struct_or_union IDENTIFIER '{' struct_declaration_list '}'{
		$$ = new_node("struct_or_union_specifier",5,$1,$2,$3,$4,$5);
	}
	| struct_or_union '{' struct_declaration_list '}'{
		$$ = new_node("struct_or_union_specifier",4,$1,$2,$3,$4);
	}
	| struct_or_union IDENTIFIER{
		$$ = new_node("struct_or_union_specifier",2,$1,$2);
	}
	;

struct_or_union:
    STRUCT{
		$$ = new_node("struct_or_union",1,$1);
	}
	| UNION{
		$$ = new_node("struct_or_union",1,$1);
	}
	;

struct_declaration_list:
    struct_declaration{
		$$ = new_node("struct_declaration_list",1,$1);		
	}
	| struct_declaration_list struct_declaration{
		$$ = new_node("struct_declaration_list",2,$1,$2);
	}
	;

struct_declaration:
    specifier_qualifier_list struct_declarator_list ';'{
		$$ = new_node("struct_declaration",3,$1,$2,$3);
	}
	;

specifier_qualifier_list:
    type_specifier specifier_qualifier_list{	
		$$ = new_node("specifier_qualifier_list",2,$1,$2);
	}
	| type_specifier{
		$$ = new_node("specifier_qualifier_list",1,$1);	
	}
	| type_qualifier specifier_qualifier_list{
		$$ = new_node("specifier_qualifier_list",2,$1,$2);
	}
	| type_qualifier{
		$$ = new_node("specifier_qualifier_list",1,$1);	
	}
	;

struct_declarator_list:
    struct_declarator{
		$$ = new_node("struct_declarator_list",1,$1);	
	}
	| struct_declarator_list ',' struct_declarator{
		$$ = new_node("struct_declarator_list",3,$1,$2,$3);
	}
	;

struct_declarator:
    declarator{
		$$ = new_node("struct_declarator",1,$1);	
	}
	| ':' constant_expression{
		$$ = new_node("struct_declarator",2,$1,$2);
	}
	| declarator ':' constant_expression{
		$$ = new_node("struct_declarator",3,$1,$2,$3);
		//形如 int a:1,结构体的空间分配
	}
	;

enum_specifier:
    ENUM '{' enumerator_list '}'{
		$$ = new_node("enum_specifier",4,$1,$2,$3,$4);
	}
	| ENUM IDENTIFIER '{' enumerator_list '}'{
		$$ = new_node("enum_specifier",5,$1,$2,$3,$4,$4);
	}
	| ENUM IDENTIFIER{
		$$ = new_node("enum_specifier",2,$1,$2);
	}
	;

enumerator_list:
    enumerator{
		//枚举
		$$ = new_node("enumerator_list",1,$1);
	}
	| enumerator_list ',' enumerator{
		$$ = new_node("enumerator_list",3,$1,$2,$3);
	}
	;

enumerator:
    IDENTIFIER{
		$$ = new_node("enumerator",1,$1);
	}
	| IDENTIFIER '=' constant_expression{
		$$ = new_node("enumerator",3,$1,$2,$3);
	}
	;

type_qualifier:
    CONST{
		$$ = new_node("type_qualifier",1,$1);
	}
	| VOLATILE{
		$$ = new_node("type_qualifier",1,$1);
	}
	;

declarator:
    pointer direct_declarator{
		$$ = new_node("declarator",2,$1,$2);
	}
	| direct_declarator{
		$$ = new_node("declarator",1,$1);
	}
	;


direct_declarator:
	IDENTIFIER {
		//变量     
		$$ = new_node("direct_declarator",1,$1);
	}
	| '(' declarator ')' {
		//.....
		$$ = new_node("direct_declarator",3,$1,$2,$3);
	}
	| direct_declarator '[' constant_expression ']' {
		//数组
		$$ = new_node("direct_declarator",4,$1,$2,$3,$4);
	}
	| direct_declarator '[' ']' {
		//数组
		$$ = new_node("direct_declarator",3,$1,$2,$3);
	}
	| direct_declarator '(' parameter_list ')' {
		//函数
		$$ = new_node("direct_declarator",4,$1,$2,$3,$4);
	}
	| direct_declarator '(' identifier_list ')' {
		//函数
		$$ = new_node("direct_declarator",4,$1,$2,$3,$4);
	}
	| direct_declarator '(' ')' {
		//函数
		$$ = new_node("direct_declarator",3,$1,$2,$3);
	}
	;

pointer:
    '*'{
		$$ = new_node("pointer",1,$1);
	}
	| '*' type_qualifier{
		$$ = new_node("pointer",2,$1,$2);
	}
	| '*' pointer{
		$$ = new_node("pointer",2,$1,$2);
	}
	| '*' type_qualifier pointer{
		$$ = new_node("pointer",3,$1,$2,$3);
	}
	;


parameter_list:
	parameter_declaration {
		$$ = new_node("parameter_list",1,$1);
	}
	| parameter_list ',' parameter_declaration {
		$$ = new_node("parameter_list",3,$1,$2,$3);
	}
	;

parameter_declaration:
	type_specifier declarator {
		$$ = new_node("parameter_declaration",2,$1,$2);
	}
	| type_specifier abstract_declarator {
		$$ = new_node("parameter_declaration",2,$1,$2);
	}
	| type_specifier {
		$$ = new_node("parameter_declaration",1,$1);
	}
	;

identifier_list:
	IDENTIFIER {
		$$ = new_node("identifier_list",1,$1);
	}
	| identifier_list ',' IDENTIFIER {
		$$ = new_node("identifier_list",3,$1,$2,$3);
	}
	;

type_name:
    specifier_qualifier_list{
		$$ = new_node("type_name",1,$1);
	}
	| specifier_qualifier_list abstract_declarator{
		$$ = new_node("type_name",2,$1,$2);
	}
	;

abstract_declarator:
    pointer{
		$$ = new_node("abstract_declarator",1,$1);
	}
	| direct_abstract_declarator{
		$$ = new_node("abstract_declarator",1,$1);
	}
	| pointer direct_abstract_declarator{
		$$ = new_node("abstract_declarator",2,$1,$2);
	}
	;

direct_abstract_declarator:
	'(' abstract_declarator ')' {
		$$ = new_node("direct_abstract_declarator",3,$1,$2,$3);
	}
	| '[' ']' {
		$$ = new_node("direct_abstract_declarator",2,$1,$2);
	}
	| '[' constant_expression ']' {
		$$ = new_node("direct_abstract_declarator",3,$1,$2,$3);
	}
	| direct_abstract_declarator '[' ']' {
		$$ = new_node("direct_abstract_declarator",3,$1,$2,$3);
	}
	| direct_abstract_declarator '[' constant_expression ']' {
		$$ = new_node("direct_abstract_declarator",4,$1,$2,$3,$4);
	}
	| '(' ')' {
		$$ = new_node("direct_abstract_declarator",2,$1,$2);
	}
	| '(' parameter_list ')' {
		$$ = new_node("direct_abstract_declarator",3,$1,$2,$3);
	}
	| direct_abstract_declarator '(' ')' {
		$$ = new_node("direct_abstract_declarator",3,$1,$2,$3);
	}
	| direct_abstract_declarator '(' parameter_list ')' {
		$$ = new_node("direct_abstract_declarator",4,$1,$2,$3,$4);
	}
	;

initializer:
	assignment_expression {
		$$ = new_node("initializer",1,$1);
	}
	| '{' initializer_list '}' {
		//列表初始化 {1,1,1}
		$$ = new_node("initializer",3,$1,$2,$3);
	}
	| '{' initializer_list ',' '}' {
		//列表初始化 {1,1,1,}
		$$ = new_node("initializer",4,$1,$2,$3,$4);
	}
	;

initializer_list:
	initializer {
		$$ = new_node("initializer_list",1,$1);
	}
	| initializer_list ',' initializer {
		$$ = new_node("initializer_list",3,$1,$2,$3);
	}
	;


statement:
	labeled_statement {
		$$ = new_node("statement",1,$1);
	}
	| compound_statement {
		$$ = new_node("statement",1,$1);
	}
	| expression_statement{
		$$ = new_node("statement",1,$1);
	}
	| selection_statement {
		$$ = new_node("statement",1,$1);
	}
	| iteration_statement {
		$$ = new_node("statement",1,$1);
	}
	| jump_statement {
		$$ = new_node("statement",1,$1);
	}
	;

labeled_statement:
	IDENTIFIER ':' statement {
		$$ = new_node("labeled_statement",3,$1,$2,$3);
	}
	| CASE logical_or_expression ':' statement {
		$$ = new_node("labeled_statement",4,$1,$2,$3,$4);
	}
	| DEFAULT ':' statement{
		$$ = new_node("labeled_statement",3,$1,$2,$3);
	}
	;

compound_statement:
	'{' '}' {
		$$ = new_node("compound_statement",2,$1,$2);
	}
	| '{' block_item_list '}' {
		$$ = new_node("compound_statement",3,$1,$2,$3);
	}
	;

block_item_list:
	block_item {
		$$ = new_node("block_item_list",1,$1);
	}
	| block_item_list block_item {
		$$ = new_node("block_item_list",2,$1,$2);
	}
	;

block_item:
	declaration {
		$$ = new_node("block_item",1,$1);
	}
	| statement {
		$$ = new_node("block_item",1,$1);
	}
	;

expression_statement:
	';' {
		$$ = new_node("expression_statement",1,$1);
	}
	| expression ';' {
		$$ = new_node("expression_statement",2,$1,$2);
	}
	;

selection_statement:
	IF '(' expression ')' statement %prec THE_FIRST_IF_IN_FRONT {
		$$ = new_node("selection_statement",5,$1,$2,$3,$4,$5);
	}
    | IF '(' expression ')' statement ELSE statement {
		$$ = new_node("selection_statement",7,$1,$2,$3,$4,$5,$6,$7);
	}
    | SWITCH '(' expression ')' statement {
		$$ = new_node("selection_statement",5,$1,$2,$3,$4,$5);
	}
    ;

iteration_statement:
	WHILE '(' expression ')' statement {
		$$ = new_node("iteration_statement",5,$1,$2,$3,$4,$5);
	}
	| DO statement WHILE '(' expression ')' ';' {
		$$ = new_node("iteration_statement",7,$1,$2,$3,$4,$5,$6,$7);
	}
	| FOR '(' expression_statement expression_statement ')' statement {
		$$ = new_node("iteration_statement",6,$1,$2,$3,$4,$5,$6);
	}
	| FOR '(' expression_statement expression_statement expression ')' statement {
		$$ = new_node("iteration_statement",7,$1,$2,$3,$4,$5,$6,$7);
	}
	| FOR '(' declaration expression_statement ')' statement {
		$$ = new_node("iteration_statement",6,$1,$2,$3,$4,$5,$6);
	}
	| FOR '(' declaration expression_statement expression ')' statement {
		$$ = new_node("iteration_statement",7,$1,$2,$3,$4,$5,$6,$7);
	}
	;

jump_statement:
	GOTO IDENTIFIER ';' {
		$$ = new_node("jump_statement",3,$1,$2,$3);
	}
	| CONTINUE ';' {
		$$ = new_node("jump_statement",2,$1,$2);
	}
	| BREAK ';' {
		$$ = new_node("jump_statement",2,$1,$2);
	}
	| RETURN ';' {
		$$ = new_node("jump_statement",2,$1,$2);
	}
	| RETURN expression ';' {
		$$ = new_node("jump_statement",3,$1,$2,$3);
	}
	;

translation_unit:
	external_declaration {
		$$ = new_node("translation_unit",1,$1);
	}
	| translation_unit external_declaration {
		$$ = new_node("translation_unit",2,$1,$2);
	}
	;

external_declaration:
	function_definition {
		$$ = new_node("external_declaration",1,$1);
	}
	| declaration {
		$$ = new_node("external_declaration",1,$1);
	}
	;

function_definition:
	declaration_specifiers declarator declaration_list compound_statement {
		$$ = new_node("function_definition",4,$1,$2,$3,$4);
	}
	| declaration_specifiers declarator compound_statement {
		$$ = new_node("function_definition",3,$1,$2,$3);
	}
	;

declaration_list:
	declaration {
		$$ = new_node("declaration_list",1,$1);
	}
	| declaration_list declaration {
		$$ = new_node("declaration_list",2,$1,$2);
	}
	;


%%

void yyerror(char const *s)
{
	printf("error_in_line_ %d：%s\n",yylineno,s);
}


int main(int argc,char* argv[]) {

	yyin=stdin;
	if(argc>1) {
		if((yyin=fopen(argv[1],"r"))==NULL) {
			printf("Can't open file %s\n",argv[1]);
			return -1;
		}
	}
	yyparse();
	printf("---------------------------lex_end----------------------------\n");

	print_AST(root,0);	//输出抽象语法树
	printf("-----------------------print_AST_end--------------------------\n");

	Praser praser(root);
	
	fclose(yyin);
	return 0;
}
