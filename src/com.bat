.\win_flex.exe .\my_compiler.l
.\win_bison.exe .\my_compiler.y -d
g++ -std=c++11 -o compiler AST.cpp my_compiler.tab.c lex.yy.c Praser.cpp AsmCode.cpp



