%option yylineno

%{

/*基于flex的c语言词法分析器
* 作者：dongzj1997
* 参考：http://www.quut.com/c/ANSI-C-grammar-l-1998.html
*/


#include "AST.h"
#include "my_compiler.tab.h"  


%}

D	    [0-9]
L	    [a-zA-Z_]
H	    [a-fA-F0-9]
E	    ([Ee][+-]?{D}+)
P       ([Pp][+-]?{D}+)
FS	    (f|F|l|L)
IS      ((u|U)|(u|U)?(l|L|ll|LL)|(l|L|ll|LL)(u|U))
INT_OCT [0][1-7][0-7]*
INT_DEX [1-9][0-9]*|[0]
INT_HEX [0][Xx]([1-9a-fA-F][0-9a-fA-F]*|[0])
FLOAT   [0-9]*[.][0-9]+([eE][+-]?[0-9]*|[0])?(F|f)?

%%


"//"[^\n]*    					    { /* comment */}
"/*"(([^\*]*(\*[^\/])?)*)"*/"		{ /* comment */}

{INT_HEX}{IS}?	{ yylval.node = new_node("CONSTANT_INT",0,yylineno);	    return(CONSTANT_INT); }
{INT_OCT}{IS}?	{ yylval.node = new_node("CONSTANT_INT",0,yylineno);	    return(CONSTANT_INT); }
{INT_DEX}{IS}?	{ yylval.node = new_node("CONSTANT_INT",0,yylineno);	    return(CONSTANT_INT); }
{FLOAT}{FS}?	{ yylval.node = new_node("CONSTANT_DOUBLE",0,yylineno);		return(CONSTANT_DOUBLE); }

"auto"			{ yylval.node = new_node("AUTO",0,yylineno);        return(AUTO); }
"break"			{ yylval.node = new_node("BREAK",0,yylineno); 	    return(BREAK); }
"case"			{ yylval.node = new_node("CASE",0,yylineno); 	    return(CASE); }
"char"			{ yylval.node = new_node("CHAR",0,yylineno); 	    return(CHAR); }
"const"			{ yylval.node = new_node("CONST",0,yylineno);       return(CONST); }
"continue"		{ yylval.node = new_node("CONTINUE",0,yylineno);    return(CONTINUE); }
"default"		{ yylval.node = new_node("DEFAULT",0,yylineno);     return(DEFAULT); }
"do"			{ yylval.node = new_node("DO",0,yylineno);		    return(DO); }
"double"		{ yylval.node = new_node("DOUBLE",0,yylineno);      return(DOUBLE); }
"else"			{ yylval.node = new_node("ELSE",0,yylineno);	    return(ELSE); }
"enum"			{ yylval.node = new_node("ENUM",0,yylineno);        return(ENUM); }
"extern"		{ yylval.node = new_node("EXTERN",0,yylineno);      return(EXTERN); }
"float"			{ yylval.node = new_node("FLOAT",0,yylineno);       return(FLOAT); }
"for"			{ yylval.node = new_node("FOR",0,yylineno);	        return(FOR); }
"if"			{ yylval.node = new_node("IF",0,yylineno);		    return(IF); }
"goto"			{ yylval.node = new_node("GOTO",0,yylineno);	    return(GOTO); }
"inline"		{ yylval.node = new_node("INLINE",0,yylineno);      return(INLINE); }
"int"			{ yylval.node = new_node("INT",0,yylineno);  	    return(INT); }
"long"			{ yylval.node = new_node("LONG",0,yylineno);        return(LONG); }
"register"		{ yylval.node = new_node("REGISTER",0,yylineno);    return(REGISTER); }
"return"		{ yylval.node = new_node("RETURN",0,yylineno);	    return(RETURN); }
"short"			{ yylval.node = new_node("SHORT)",0,yylineno);      return(SHORT); }
"signed"		{ yylval.node = new_node("SIGNED",0,yylineno);      return(SIGNED); }
"sizeof"		{ yylval.node = new_node("SIZEOF",0,yylineno);      return(SIZEOF); }
"static"		{ yylval.node = new_node("STATIC",0,yylineno);      return(STATIC); }
"struct"		{ yylval.node = new_node("STRUCT",0,yylineno);      return(STRUCT); }
"switch"		{ yylval.node = new_node("SWITCH",0,yylineno);	    return(SWITCH); }
"typedef"		{ yylval.node = new_node("TYPEDEF",0,yylineno);     return(TYPEDEF); }
"union"			{ yylval.node = new_node("UNION",0,yylineno);       return(UNION); }
"unsigned"		{ yylval.node = new_node("UNSIGNED",0,yylineno);    return(UNSIGNED); }
"void"			{ yylval.node = new_node("VOID",0,yylineno);	    return(VOID); }
"while"			{ yylval.node = new_node("WHILE",0,yylineno);	    return(WHILE); }

{L}({L}|{D})* 	{ yylval.node =new_node("IDENTIFIER",0,yylineno);	return(IDENTIFIER); }
L?\"(\\.|[^\\"\n])*\"	{ yylval.node =new_node("STRING_LITERAL",0,yylineno);	return(STRING_LITERAL); }

";"		{ yylval.node = new_node(";",0,yylineno);	return(';'); }
","		{ yylval.node = new_node(",",0,yylineno);	return(','); }
":"		{ yylval.node = new_node(":",0,yylineno);	return(':'); }
"="		{ yylval.node = new_node("=",0,yylineno);	return('='); }
"{"		{ yylval.node = new_node("{",0,yylineno);	return('{'); }
"}"		{ yylval.node = new_node("}",0,yylineno);	return('}'); }
"("		{ yylval.node = new_node("(",0,yylineno);	return('('); }
")"		{ yylval.node = new_node(")",0,yylineno);	return(')'); }
"["		{ yylval.node = new_node("[",0,yylineno);	return('['); }
"]"		{ yylval.node = new_node("]",0,yylineno);	return(']'); }
"."		{ yylval.node = new_node(".",0,yylineno);	return('.'); }
"&"		{ yylval.node = new_node("&",0,yylineno);	return('&'); }
"!"		{ yylval.node = new_node("!",0,yylineno);	return('!'); }
"~"		{ yylval.node = new_node("~",0,yylineno);	return('~'); }
"-"		{ yylval.node = new_node("-",0,yylineno);	return('-'); }
"+"		{ yylval.node = new_node("+",0,yylineno);	return('+'); }
"*"		{ yylval.node = new_node("*",0,yylineno);	return('*'); }
"/"		{ yylval.node = new_node("/",0,yylineno);	return('/'); }
"%"		{ yylval.node = new_node("%",0,yylineno);	return('%'); }
"<"		{ yylval.node = new_node("<",0,yylineno);	return('<'); }
">"		{ yylval.node = new_node(">",0,yylineno);	return('>'); }
"^"		{ yylval.node = new_node("^",0,yylineno);	return('^'); }
"|"		{ yylval.node = new_node("|",0,yylineno);	return('|'); }
"?"		{ yylval.node = new_node("?",0,yylineno);	return('?'); }

"..."	{ yylval.node = new_node("ELLIPSIS",0,yylineno);        return(ELLIPSIS); }
">>="	{ yylval.node = new_node("RIGHT_ASSIGN",0,yylineno);	return(RIGHT_ASSIGN); }
"<<="	{ yylval.node = new_node("LEFT_ASSIGN",0,yylineno); 	return(LEFT_ASSIGN); }
"+="	{ yylval.node = new_node("ADD_ASSIGN",0,yylineno);		return(ADD_ASSIGN); }
"-="	{ yylval.node = new_node("SUB_ASSIGN",0,yylineno);		return(SUB_ASSIGN); }
"*="	{ yylval.node = new_node("MUL_ASSIGN",0,yylineno);		return(MUL_ASSIGN); }
"/="	{ yylval.node = new_node("DIV_ASSIGN",0,yylineno);		return(DIV_ASSIGN); }
"%="	{ yylval.node = new_node("MOD_ASSIGN",0,yylineno);		return(MOD_ASSIGN); }
"&="	{ yylval.node = new_node("AND_ASSIGN",0,yylineno);		return(AND_ASSIGN); }
"^="	{ yylval.node = new_node("XOR_ASSIGN",0,yylineno);		return(XOR_ASSIGN); }
"|="	{ yylval.node = new_node("OR_ASSIGN",0,yylineno);		return(OR_ASSIGN); }
">>"	{ yylval.node = new_node("RIGHT_OP",0,yylineno);		return(RIGHT_OP); }
"<<"	{ yylval.node = new_node("LEFT_OP",0,yylineno);	    	return(LEFT_OP); }
"++"	{ yylval.node = new_node("INC_OP",0,yylineno);			return(INC_OP); }
"--"	{ yylval.node = new_node("DEC_OP",0,yylineno);			return(DEC_OP); }
"->"	{ yylval.node = new_node("PTR_OP",0,yylineno);			return(PTR_OP); }
"&&"	{ yylval.node = new_node("AND_OP",0,yylineno);			return(AND_OP); }
"||"	{ yylval.node = new_node("OR_OP",0,yylineno);			return(OR_OP); }
"<="	{ yylval.node = new_node("LE_OP",0,yylineno);			return(LE_OP); }
">="	{ yylval.node = new_node("GE_OP",0,yylineno);			return(GE_OP); }
"=="	{ yylval.node = new_node("EQ_OP",0,yylineno);			return(EQ_OP); }
"!="	{ yylval.node = new_node("NE_OP",0,yylineno);			return(NE_OP); }

[\t\v\n\f ]		{  }
.			    { /*Illegal character*/ }

%%


int yywrap() {
	return 1;
}
