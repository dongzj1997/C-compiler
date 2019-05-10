#include "Praser.h"

using namespace std;

Praser::Praser(AST* root) {//构造函数
	this->root = root;
	praserInit();
	printf("---------------------debug_info_end---------------------------\n");
	print_code();
	printf("---------------------inner_code_end---------------------------\n");
	asmcode.CodeGen(codeList);
	asmcode.printCode();
	printf("--------------------objcoed_gen_end---------------------------\n");
}

void Praser::praserInit() { //初始化
	Block wholeBlock; //创建整个程序的代码块信息（全局）
	blockStack.push_back(wholeBlock);  

	//加入内置函数 scan：读入一个int 并返回  print：打印一个int值
	funcNode print;
	print.name = "print";
	print.rtype = "void";
	varNode pnode;
	pnode.type = "int";
	print.paralist.push_back(pnode);
	funcPool.insert({ "print", print });

	funcNode scan;
	scan.name = "scan";
	scan.rtype = "int";
	funcPool.insert({"scan",scan});


	praserAST(root);		//开始分析语法树

	blockStack.pop_back();
}

void Praser::praserAST(struct AST* node) {
	//cout << "at " << node->type << endl;
	if (node == NULL)
		return;

	else if (node->type == "function_definition") { //解析函数
		praser_function_definition(node);
		return;
	}
	else if (node->type == "declaration") {
		praser_declaration(node);
		return;
	}
	
	else if (node->type == "statement") {
		praser_statement(node);
		return;
	}  
	else{//继续向下递归分析
		praserAST(node->left);
		praserAST(node->right);
	}

}

void Praser::praser_function_definition(struct AST* node) {
	AST* type_specifier;
	if(node->left->type=="type_specifier" ){
		type_specifier = node->left;
	}
	else{
		cout<<"Debug: 函数的返回值不是type_specifier，可能是一个指针或者其他修饰字符:"<<node->left->type<<endl;
	}
	
	AST* declarator = node->left->right;
	//此处的declarator为第一层declarator，即direct_declarator->direct_declarator '(' ')' |direct_declarator '(' identifier_list ')'

	AST* compound_statement = declarator->right;
	
	string funcType = type_specifier->left->text;
	string funcName = declarator->left->left->text;

	bool isdeclared = false;
	funcNode declarFunc;

	if (funcPool.find(funcName) != funcPool.end()) {
		//该函数名在funcPool中找到，函数重复定义
		cout<<"Debug: 函数定义或者声明过"<<endl;
		if (funcPool[funcName].isdefinied) {
			error(declarator->left->left->line, "函数重复定义：" + funcName );
		}
		//函数事先声明过但是没有定义
		else {
			isdeclared = true;
			//先删除掉函数池中的函数的声明
			declarFunc = funcPool[funcName];
			funcPool.erase(funcPool.find(funcName));
		}
	}

	Block funBlock;
	funBlock.isfunc = true;
	funBlock.func.name = funcName;
	funBlock.func.rtype = funcType;
	funBlock.func.isdefinied = true;
	//将函数记录在块内并添加到函数池
	blockStack.push_back(funBlock);
	funcPool.insert({funcName,funBlock.func});

	cout<<"Debug:成功创建Block和插入了funcPool,函数："<<funcName<<endl;

	addCode("FUNC " + funcName + ":");

	//获取函数形参列表
	if(declarator->left->right->right->type == "parameter_list"){
		cout<<"Debug:开始解析一个带参数（parameter_list）的 function"<<endl;
		praser_parameter_list(declarator->left->right->right, funcName,true);
		cout<<"Debug:参数解析完毕"<<endl;
	}//传入parameter_list
	//此时函数池中的func已经添加了参数列表
	funcNode func = funcPool[funcName];
	
	//如果函数事先声明过，则比较函数的参数列表和返回类型
	if (isdeclared) {
		if (func.rtype != declarFunc.rtype) {
			error(type_specifier->left->line, "函数返回值的定义和声明不一致.");
		}
		cout << funBlock.func.paralist.size() << endl;
		if (func.paralist.size() != declarFunc.paralist.size()) {
			error(declarator->left->right->right->line, "函数参数个数定义和声明不一致.");
		}
		for (int i = 0; i < funBlock.func.paralist.size(); i++) {
			if (func.paralist[i].type != declarFunc.paralist[i].type)
				error(declarator->left->right->right->line, "函数参数：" + funBlock.func.paralist[i].name + "的定义和声明不一致。" );
		}
	}

	//更新Block中func的参数列表
	funBlock.func = func;
	//分析函数的正文
	praserAST(compound_statement->left->right);

	//函数结束后，弹出相应的block
	blockStack.pop_back();

}

void Praser::praser_parameter_list(struct AST* node,string funcName,bool definite) {
	if (node->left->type == "parameter_list") {
		//形如 parameter_list   ->   parameter_list ',' parameter_declaration
		praser_parameter_list(node->left, funcName,definite);
		praser_parameter_declaration(node->left->right->right, funcName,definite);
	}
	else if (node->left->type == "parameter_declaration") {
		praser_parameter_declaration(node->left,funcName,definite);
	}
	else {
		cout<<"Debug:praser_parameter_list失败：传入类型不当的结点:"<<node->left->type<<endl;
	}
}

//获取单个形参内容,函数定义需要获取形参，声明则不需要
void Praser::praser_parameter_declaration(struct AST* node, string funcName,bool definite) {

	AST* type_specifier = node->left;
	AST* declarator = node->left->right;

	string typeName = type_specifier->left->text;

	//暂时只考虑变量，不考虑数组作为形参
	string varName = declarator->left->text;
	varNode newnode;
	newnode.name = varName;
	newnode.type = typeName;
	if (definite) {
		newnode.num = varNum++;
		blockStack.back().func.paralist.push_back(newnode);
		cout<<"Debug:成功将参数:"<<varName<<"添加到:"<<funcName<<endl;
	}

	funcPool[funcName].paralist.push_back(newnode);
	
	//将函数的形参添加到当前块的变量池中
	blockStack.back().varMap.insert({varName,newnode});
	addCode("PARAM_IN var" + inttostr(newnode.num) );
		
}



void Praser::praser_compound_statement(struct AST* node) {
	//继续分析处理compound_statement
	//compound_statement可以是 declaration 或者是statement
	//对于{}块中的代码，创建一个新的块，新的命名空间
	Block newblock;
	blockStack.push_back(newblock);
	
	praserAST(node->left->right);  //可以和上面合并

	blockStack.pop_back();
}



void Praser::praser_declaration(struct AST *node) {
	
	cout<<"Debug:开始解析 praser_declaration"<<endl;
	struct AST* begin = node->left;	//begin:type_specifier
	if (begin->right->type == ";")
		return ;// int; 在C语言中是合法的
	
	string vartype = begin->left->text;
	struct AST* decl = begin->right;	//init_declarator_list 或者是 init_declarator
	praser_init_declarator_list(vartype, decl);
	return ;
}

void Praser::praser_init_declarator_list(string vartype, struct AST* node) {
	if (node->left->type == "init_declarator_list") {
		praser_init_declarator_list(vartype, node->left);
		praser_init_declarator(vartype, node->left->right->right);
	}
	else if (node->left->type == "init_declarator") {
		praser_init_declarator(vartype, node->left);
	}
	else{
		cout<<"Debug: praser_init_declarator_list失败"<<endl;
	}
}



//未来修改意见：将带=和不带=的解析变量名 的代码合并
void Praser::praser_init_declarator(string vartype, struct AST* node) {
	
	struct AST* declarator = node->left;
	cout<<"Debug:wqeqw 开始初始化变量："<<declarator->left->text<<endl;
	if (!declarator->right) {//单个变量，无初始化
		//获取变量的名字
		if (declarator->left->type == "IDENTIFIER") {
			struct AST* id = declarator->left;
			string varname = id->text;

			if ( blockStack.back().varMap.find(varname) == blockStack.back().varMap.end() ) {
				//变量还没有定义过
				varNode newvar;
				newvar.name = varname;
				newvar.type = vartype;
				newvar.num = varNum++;
				blockStack.back().varMap.insert({ varname,newvar });
			}
			
			else{
				error(declarator->left->line, "变量重复定义");
		
			}
		}
		else{
			cout<<"Debug:ads 函数声明，数组声明暂时未完成"<<endl;
		}
			
	}
	//有初始化
	else if (declarator->right->type == "=") {	
		//获取变量的名字
		varNode newvar;
		if (declarator->left->type == "IDENTIFIER") {
			struct AST* id = declarator->left;
			string varname = id->text;
			if ( blockStack.back().varMap.find(varname) == blockStack.back().varMap.end() ) {
				newvar.name = varname;
				newvar.type = vartype;
				newvar.num = varNum++;
				blockStack.back().varMap.insert({ varname,newvar });
			}
			else {
				error(declarator->left->line, "变量重复定义");
			}
		}
		else {
			error(declarator->left->line, "其他情况未完成");
		}


		AST* initializer = declarator->right->right;
		if (initializer == NULL) {
			error(declarator->line, "缺少赋值语句");
		}
		else if(initializer->left->type == "assignment_expression"){
			varNode rnode = praser_assignment_expression(initializer->left);

			if( rnode.num<0){//是临时变量 如int a=1+1;
				addCode("var"+ inttostr(newvar.num) +" = "+ rnode.name);
			}
			else{//是已知变量 如 int a=b;
				addCode("var"+ inttostr(newvar.num) +" = var"+inttostr(rnode.num));
			}

			string rtype = rnode.type;
			if (rtype != vartype){
				error(initializer->left->line, "Wrong type to variable " + declarator->left->text + ": " + rtype + " to " + vartype);
			}

		}else{
			cout<<"Debug:vxc initializer推出的其他带{}的项，待完成"<<endl;
		}
	}
	else error(declarator->right->line, "错误的初始化语句");
}


varNode Praser::praser_assignment_expression(struct AST* assign_exp) {	//返回变量节点
	cout<<"Debug:czxc 开始解析赋值语句:"<<assign_exp->type<<endl;
	//此处将三元表达式省去，assignment_expression可直接推出logical_or_expression
	//assignment_expression可以是赋值表达式unary_expression assignment_operator assignment_expression
	//或者没有赋值号的表达式conditional_expression
	//逻辑表达式子 要注意短路求值 的特性
	struct AST* Temp1=assign_exp;

	if(assign_exp->type=="assignment_expression"){
		Temp1=assign_exp->left;
	}

	if(assign_exp->type!="assignment_expression"||Temp1->right==NULL){   //只是表达式，没有赋值语句 如1+1;
		if (Temp1->type == "logical_or_expression") {
			return praser_logical_or_expression(Temp1);
		}
		else if (Temp1->type == "logical_and_expression") {
			return praser_logical_and_expression(Temp1);
		}
		//inclusive_or_expression 单个|
		//exclusive_or_expression 异或 ^
		//and_expression 单个&
		else if (Temp1->type == "equality_expression") {
			return praser_equality_expression(Temp1);
		}

		else if (Temp1->type == "relational_expression") {
			return praser_relational_expression(Temp1);
		}

		//shift_expression <<  >> 

		else if (Temp1->type == "additive_expression") {
			return praser_additive_expression(Temp1);
		}
		else if (Temp1->type == "multiplicative_expression") {

			return praser_multiplicative_expression(Temp1);
		}

		else if(Temp1->type == "postfix_expression" ) {
			return praser_postfix_expression(Temp1);
		}

		else if(Temp1->type == "primary_expression" ) {
			return praser_primary_expression(Temp1);
		}
		else{
			//ERROR;
		}
	}
// assignment_expression -> 赋值语句
// unary_expression assignment_operator assignment_expression
	else if (Temp1->type == "primary_expression") {
		//如int a[b=4];   int i=b=1;等等
		struct AST* primary_exp = Temp1;
		string op = Temp1->right->left->type;
		struct AST* next_assign_exp = Temp1->right->right;
		varNode node1 = praser_primary_expression(primary_exp);
		varNode node2 = praser_assignment_expression(next_assign_exp);
		varNode node3;
		if (op == "=") {
			node3 = node2;
		}
		else {
			cout<<"Debug:eqw 其他赋值符号，如+=等"<<endl;
		}

		if( node3.num<0){//是临时变量 如 a=1+1;
			addCode("var"+ inttostr(node1.num) +" = "+ node3.name);
		}
		else{//是已知变量 如 a=b;
			addCode("var"+ inttostr(node1.num) +" = var"+inttostr(node3.num));
		}		

		return node1;
	}
	else{
		cout<<"Debug:开始解析未完成的赋值语句"<<assign_exp->type<<endl;
	}
}

varNode Praser::praser_logical_or_expression(struct AST* logical_or_exp) {
	//logical_or_expression -> logical_or_expression OR_OP logical_and_expression
	varNode node1 = praser_assignment_expression(logical_or_exp->left);

	string label1 = getLabelName();
	string label2 = getLabelName();
	string tempname = "temp" + inttostr(tempNum);
	++tempNum;
	varNode newnode = createTempVar(tempname, node1.type);
	addCode("IF " + getNodeName(node1) + " == FALSE" + " GOTO " + label1);
	addCode(newnode.name + " = "  + node1.name);
	addCode("GOTO " + label2);//跳出整个判断体
	addCode(label1 + ":");
	varNode node2 = praser_assignment_expression(logical_or_exp->left->right->right);
	addCode(newnode.name + " = "  + node2.name);
	addCode(label2 + ":");
	return newnode;
}

varNode Praser::praser_logical_and_expression(struct AST* logical_and_exp) {
	varNode node1 = praser_assignment_expression(logical_and_exp->left);
	string label1 = getLabelName();
	string label2 = getLabelName();
	string tempname = "temp" + inttostr(tempNum);
	++tempNum;
	varNode newnode = createTempVar(tempname, node1.type);
	blockStack.back().varMap.insert({ tempname,newnode });
	addCode("IF " + getNodeName(node1) + " != 0" + " GOTO " + label1);
	addCode(newnode.name + " = "  + node1.name);
	addCode("GOTO " + label2);//跳出整个判断体
	addCode(label1 + ":");
	varNode node2 = praser_assignment_expression(logical_and_exp->left->right->right);
	addCode(newnode.name + " = "  + node2.name);
	addCode(label2 + ":");
	return newnode;
}


//开始解析== 和!= 表达式
varNode Praser::praser_equality_expression(struct AST* equality_exp) {
	if (equality_exp->left->right->type == "EQ_OP" || equality_exp->left->right->type == "NE_OP") {
		string op;
		if (equality_exp->left->right->type == "EQ_OP")
			op = "==";
		else op = "!=";

		varNode node1 = praser_assignment_expression(equality_exp->left);
		varNode node2 = praser_assignment_expression(equality_exp->left->right->right);

		if (node1.type != node2.type) {
			error(equality_exp->left->right->line, "类型不匹配！");
		}

		string tempname = "temp" + inttostr(tempNum);
		++tempNum;

		varNode newnode = createTempVar(tempname, "int");
		blockStack.back().varMap.insert({ tempname,newnode});
		addCode(Gen_IR(tempname, op, node1, node2));


		return newnode;
	}
}
varNode Praser::praser_relational_expression(struct AST* relational_exp) {

	string op = relational_exp->left->right->type;
	if (op == "LE_OP")
		op = "<=";
	else if (op == "GE_OP")
		op = ">=";
	if (op == ">" || op == "<" || op == ">=" || op == "<=") {
		varNode node1 = praser_assignment_expression(relational_exp->left);
		varNode node2 = praser_assignment_expression(relational_exp->left->right->right);

		if (node1.type != node2.type) {
			error(relational_exp->left->right->line, "类型不匹配！");
		}

		string tempname = "temp" + inttostr(tempNum);
		++tempNum;

		varNode newnode = createTempVar(tempname, "int");
		blockStack.back().varMap.insert({ tempname,newnode });
		addCode(Gen_IR(tempname, op, node1, node2));


		return newnode;
	}
	
}
//开始解析+号表达式
varNode Praser::praser_additive_expression(struct AST* additive_exp) {
	if(additive_exp->left->right->type == "+" || additive_exp->left->right->type == "-") {
		varNode node1 = praser_assignment_expression(additive_exp->left);
		varNode node2 = praser_assignment_expression(additive_exp->left->right->right);
		//递归下降

		if (node1.type != node2.type) {
			cout<<"Debug:不同的参数类型（+）："<< node1.type << "和" <<node2.type<<endl;
			error(additive_exp->left->right->line, "Different type for two variables.");
		}

		string tempname = "temp" + inttostr(tempNum);
		++tempNum;
		varNode newnode = createTempVar(tempname, node1.type);
		blockStack.back().varMap.insert({ tempname,newnode});

		addCode(Gen_IR(tempname, additive_exp->left->right->type, node1, node2));
		return newnode;
	}
	else{
	cout<<"Debug:dsa 错误进入praser_additive_expression"<<endl;
	}
}

varNode Praser::praser_multiplicative_expression(struct AST* mult_exp) {

	varNode node1 = praser_assignment_expression(mult_exp->left);
	varNode node2 = praser_assignment_expression(mult_exp->left->right->right);

	if (node1.type != node2.type) {
		cout<<"Debug:不同的参数类型："<< node1.type << "和" <<node2.type<<endl;
		error(mult_exp->left->right->line, "Different type for two variables.");
	}

	string tempname = "temp" + inttostr(tempNum);
	++tempNum;
	varNode newNode = createTempVar(tempname, node1.type);
	blockStack.back().varMap.insert({ tempname,newNode });

	addCode(Gen_IR(tempname, mult_exp->left->right->type,node1,node2));
	return newNode;
}

varNode Praser::praser_postfix_expression(struct AST* post_exp) {

	if (post_exp->left->type == "primary_expression"&&post_exp->left->right==NULL) {
		AST* primary_exp = post_exp->left;
		return praser_assignment_expression(primary_exp);
		//这一段代码估计永远都进不去
	}

	else if (post_exp->left->right->type == "(") {
		//函数调用
		string funcName = post_exp->left->left->text;
		varNode newNode;
		cout<<"Debug:尝试调用函数："<<funcName<<endl;
		if (funcPool.find(funcName) == funcPool.end()) {
			error(post_exp->left->left->left->line, "Undefined function " + funcName);
		}

		if (post_exp->left->right->right->type == "argument_expression_list") {
			AST* argument_exp_list = post_exp->left->right->right;
			praser_argument_expression_list(argument_exp_list, funcName);

		}

		funcNode func = funcPool[funcName];
		
		if (func.rtype == "void") {
			addCode("CALL " + funcName);
		}
		else {
			string tempname = "temp" + inttostr(tempNum);
			++tempNum;

			newNode = createTempVar(tempname, funcPool[funcName].rtype);
			blockStack.back().varMap.insert({ tempname,newNode });
			addCode(tempname + " = CALL " + funcName);

		}

		return newNode;
		
	}

}
//解析对调用函数时的参数
void Praser::praser_argument_expression_list(struct AST* node, string funcName) {
	AST* argu_exp_list = node->left;
	funcNode func = funcPool[funcName];
	int i = 0;
	while (argu_exp_list->type == "argument_expression_list") {
		//不断循环，直到argument_expression_list指向的结点为assignment_expression
		varNode rnode = praser_assignment_expression(argu_exp_list->right->right);

		if(rnode.num<0){
			addCode("PARAM_PREP "+rnode.name);
		}else{
			addCode("PARAM_PREP var"+inttostr(rnode.num));
		}
		

		argu_exp_list = argu_exp_list->left;
		i++;
		if (func.paralist[func.paralist.size() - i].type != rnode.type) {
			error(argu_exp_list->line, "Wrong type arguments to function " + funcName);
		}
	}
	varNode rnode = praser_assignment_expression(argu_exp_list);
	if(rnode.num<0){
			addCode("PARAM_PREP "+rnode.name);
		}else{
			addCode("PARAM_PREP var"+inttostr(rnode.num));
		}
	i++;
	if (func.paralist[func.paralist.size() - i].type != rnode.type) {
		error(argu_exp_list->line, "Wrong type arguments to function " + funcName);
	}
	if (i != func.paralist.size()) {
		error(argu_exp_list->line, "The number of arguments doesn't equal to the function parameters number.");
	}
}



varNode Praser::praser_primary_expression(struct AST* primary_exp) {
	if (primary_exp->left->type == "IDENTIFIER") {
		string content = primary_exp->left->text;
		varNode rnode = lookupNode(content);
		if (rnode.num < 0) {
			error(primary_exp->left->line, "Undefined variable " + content);
		}
		return rnode;
	}
	else if (primary_exp->left->type == "CONSTANT_INT") {
		string content = primary_exp->left->text;
		string tempname = "temp" + inttostr(tempNum);
		++tempNum;
		
		varNode newNode = createTempVar(tempname, "int");
		blockStack.back().varMap.insert({ tempname,newNode });
		addCode(tempname + " = "  + content);
		return newNode;
	}
	else if (primary_exp->left->type == "CONSTANT_FLOAT") {
		string content = primary_exp->left->text;
		string tempname = "temp" + inttostr(tempNum);
		++tempNum;
		
		varNode newNode = createTempVar(tempname, "FLOAT");

		blockStack.back().varMap.insert({ tempname,newNode});
		addCode(tempname + " = F" + content);
		return newNode;
	}
	else if (primary_exp->left->type == "(") {
		struct AST* expression = primary_exp->left->right;
		return praser_assignment_expression(expression);
	}
}

void Praser::praser_statement(struct AST* node) {
	struct AST* next = node->left;
	if (node->left->type == "labeled_statement") {
		praser_labeled_statement(node->left);
	}
	else if(node->left->type == "compound_statement") {//复合语句  {。。。}
		praser_compound_statement(node->left);
	}
	else if (node->left->type == "expression_statement") { //单个;或者 expression ';'
		praser_expression_statement(node->left);
	}
	else if (node->left->type == "selection_statement") { // if or switch
		praser_selection_statement(node->left);
	}
	else if (node->left->type == "iteration_statement") {//迭代语句 for while do-while
		praser_iteration_statement(node->left);
	}
	else if (node->left->type == "jump_statement") { //goto continue break return
		praser_jump_statement(node->left);
	}
	else {
		cout<<"Debug:dsa praser_statement,未定义的语句："<<node->left->type<<endl;
	}

}
void Praser::praser_expression_statement(struct AST *node) {
	if (node->left->type == "expression") {
		praser_expression(node->left);
	}
	else if(node->left->type == "assignment_expression"){
		praser_assignment_expression(node->left);
	}
	else if(node->left->type == ";"){
		//空语句 单个;
	}
	else{
		//ERROR
	}

}

//expression
varNode Praser::praser_expression(struct AST* node) {
	//对于逗号运算符，先计算右边，返回左边的值，没毛病
	if (node->type == "assignment_expression") {
		return praser_assignment_expression(node);
	}
	else if(node->left->type == "expression") {
		praser_assignment_expression(node->left->right->right);
		return praser_expression(node->left);
	}
	else if (node->left->type == "assignment_expression") {
		return praser_assignment_expression(node->left);
	}
	else{
		cout<<"Debug:vxc praser_expression："<<node->left->type<<endl;
	}
}

//只解析if语句
void Praser::praser_selection_statement(struct AST* node) {
	cout<<"Debug:142 开始解析IF语句："<<node->left->type<<endl;
	if (node->left->type == "IF") {
		if (node->left->right->right->right->right->right == NULL) {
			//添加一个新的block  没有else语句
			Block newblock;
			blockStack.push_back(newblock);

			AST* expression = node->left->right->right;
			varNode exp_rnode = praser_expression(expression);
			AST* statement = node->left->right->right->right->right;

			string label1 = getLabelName();
			string label2 = getLabelName();



			addCode("IF " + getNodeName(exp_rnode) + " != 0" + " GOTO " + label1);
		
			
			addCode("GOTO " + label2);
			addCode(label1 + ":");


			praser_statement(statement);
			
			addCode(label2 + ":");

			//弹出添加的block
			blockStack.pop_back();

		}
		else if (node->left->right->right->right->right->right->type == "ELSE") {
			//添加一个新的block
			Block newblock1;
			blockStack.push_back(newblock1);

			AST* expression = node->left->right->right;
			varNode exp_rnode = praser_expression(expression);
			AST* statement1 = node->left->right->right->right->right;
			AST* statement2 = node->left->right->right->right->right->right->right;

			string label1 = getLabelName();
			string label2 = getLabelName();
			string label3 = getLabelName();


			addCode("IF " + getNodeName(exp_rnode) + " != 0 "  + " GOTO " + label1);
			addCode("GOTO " + label2);
			addCode(label1 + ":");

			praser_statement(statement1);
			
			addCode("GOTO " + label3);
			//弹出添加的block
			blockStack.pop_back();

			//else
			addCode(label2 + ":");

			Block newblock2;
			blockStack.push_back(newblock2);

			praser_statement(statement2);

			addCode(label3 + ":");

			blockStack.pop_back();

		}
	}
	else if (node->left->type == "SWITCH") {
		cout<<"Debug:dsa praser_selection_statement,未定义的语句："<<node->left->type<<endl;
	}
	else{
		cout<<"Debug:dsa praser_selection_statement,未定义的语句："<<node->left->type<<endl;
	}
	
}

void Praser::praser_iteration_statement(struct AST* node) {
	if (node->left->type == "WHILE") {

		//添加一个新的block
		Block newblock;
		blockStack.push_back(newblock);

		struct AST* expression = node->left->right->right;
		struct AST* statement = node->left->right->right->right->right;

		string label1 = getLabelName(); //判断语句的开始
		string label2 = getLabelName(); //循环体语句
		string label3 = getLabelName(); //循环外语句

		blockStack.back().continueLabelname = label1;
		blockStack.back().breakLabelname = label3;
		
		addCode(label1 + ":");

		varNode var = praser_expression(expression);



		addCode("IF " + getNodeName(var) + " != 0"  + " GOTO " + label2);
	
		addCode("GOTO " + label3);
		addCode(label2 + ":");

		praser_statement(statement);

		addCode("GOTO " + label1);
		addCode(label3 + ":");
		

		//弹出添加的block
		blockStack.pop_back();
	}
	else if (node->left->type == "DO") {
		//添加一个新的block
		Block newblock;
		blockStack.push_back(newblock);

		struct AST* statement = node->left->right;
		struct AST* expression = node->left->right->right->right->right;

		string label1 = getLabelName(); //循环体开始
		string label2 = getLabelName(); //循环体外

		blockStack.back().continueLabelname = label1;
		blockStack.back().breakLabelname = label2;

		addCode(label1 + ":");

		praser_statement(statement);

		varNode var = praser_expression(expression);





		addCode("IF " + getNodeName(var) + " != 0"  + " GOTO " + label1);


		addCode(label2 + ":");

		//弹出添加的block
		blockStack.pop_back();

	}
	else if(node->left->type == "FOR") {
		Block newblock;
		blockStack.push_back(newblock);

		AST* exp_state1 = node->left->right->right;  // i=0;
		AST* exp_state2 = exp_state1->right; 		 // i<10;
		AST* exp_state3 = exp_state2->right;		 // i++ 或)
		AST* exp_state4 = exp_state3->right;         // )或者statement
		AST* exp_state5 = exp_state4->right;         //statement 或者NULL

		varNode var;

		if (exp_state1->type == "expression_statement") {
			//没有新定义变量
			praser_expression_statement(exp_state1);
		}else if(exp_state1->type == "declaration"){
			praser_declaration(exp_state1);
		}else{
			cout<<"Dubug:fsdi 未知的错误 FOR循环中"<<endl;
		}

		string label1 = getLabelName();
		string label2 = getLabelName();
		string label3 = getLabelName();
		
		blockStack.back().continueLabelname = label1;
		blockStack.back().breakLabelname = label3;

		addCode(label1 + " :");
		
		if(exp_state2->left->type==";"){
			addCode("GOTO " + label2);
		}
		else{
			var = praser_expression(exp_state2->left);
			addCode("IF " + getNodeName(var) + " != 0" + " GOTO " + label2);
		}

		addCode("GOTO " + label3);
		addCode(label2 + " :");
		if (exp_state3->type == ")") {
			//FOR '(' expression_statement expression_statement ')'statement
			//如 for (i=0;i<10;)

			praser_statement(exp_state4);
			

		}else{
			praser_statement(exp_state5);
			praser_expression(exp_state3);
		}
		
		addCode("GOTO " + label1);
		addCode(label3 + " :");
		blockStack.pop_back();
	}
}




void Praser::praser_jump_statement(struct AST* node) {
	if (node->left->type == "GOTO") {
		string labele_name=node->left->right->text;
		string label1;
		if(labelPool.find(labele_name)!=labelPool.end()) {
			label1=labelPool[labele_name];
			addCode("GOTO " + label1);
		}else{
			error(node->left->right->line, "未定义的标签:" + labele_name);
		}

	}
	else if (node->left->type == "CONTINUE") {
		string continue_label="";
		int N = blockStack.size();
		for (int i = N - 1; i >= 0; i--) {
			if (blockStack[i].continueLabelname!=""){
				continue_label=blockStack[i].continueLabelname;
				break;
			}
		}
		if(continue_label==""){
			error(node->left->line, "没有相应的continue位置");
		}else{
			addCode("GOTO " + continue_label);
		}

	}
	else if (node->left->type == "BREAK") {
		string break_label="";
		int N = blockStack.size();
		for (int i = N - 1; i >= 0; i--) {
			if (blockStack[i].breakLabelname!=""){
				break_label=blockStack[i].breakLabelname;
				break;
			}
		}
		if(break_label==""){
			error(node->left->line, "没有相应的break位置");
		}else{
			addCode("GOTO " + break_label);
		}

	}
	else if (node->left->type == "RETURN") {
		string funcType = getFuncRType();
		if (node->left->right->type != ";") {//return expression
			varNode rnode = praser_expression(node->left->right);
			if(rnode.num<0){
				addCode("RETURN " + rnode.name );
			}else{
				addCode("RETURN var" + inttostr(rnode.num) );
			}
			
			if (rnode.type != funcType) {
				cout <<"Dubug:123 返回类型不匹配"<< rnode.type <<"and"<<funcType <<endl;
				error(node->left->right->line, "You must return a value with type:" + funcType);
			}
		}
		else if (node->left->right->type == ";"){//return ;
			addCode("RETURN");
			if (funcType != "void") {
				error(node->left->right->line, "You must return a value with type:" + funcType);
			}
		}
		else {
			cout<<"Dubug:dqw 未知的错误"<<endl;
		}
	}
}

void Praser:: praser_labeled_statement(struct AST* node){
	string labele_name = node->left->text;
	string label1 = getLabelName();

	addCode(label1 + ":");
	labelPool.insert({labele_name,label1});

	praser_statement(node->left->right->right);

}



struct varNode Praser::createTempVar(string name, string type) {
	varNode var;
	var.name = name;
	var.type = type;
	var.num = -1;
	return var;
}

struct varNode Praser::lookupNode(string name) {
	int N = blockStack.size();
	for (int i = N - 1; i >= 0; i--) {
		if (blockStack[i].varMap.find(name) != blockStack[i].varMap.end())
			return blockStack[i].varMap[name];
	}
	varNode temp;
	temp.num = -1;
	return temp;
}


void Praser::addCode(string str)
{
	codeList.push_back(str);
}


void Praser::print_code() {
	for (string s : codeList)
	{
		if (s.find("FUNC") != 0 && s.find("label") != 0)
		{
			cout << "\t";
		}
		cout << s << endl;
	}
}



string Praser::getFuncRType() {
	int N = blockStack.size();
	for (int i = N - 1; i >= 0; i--) {
		if (blockStack[i].isfunc)
			return blockStack[i].func.rtype;
	}
	return "";
}

string Praser::getLabelName()
{
	return "label_" + inttostr(labelNum++);
}

string Praser::getNodeName(varNode node)
{

	if (node.num < 0)
	{
		return node.name;
	}
	else
		return ("var" + inttostr(node.num));
}

string Praser::Gen_IR(string tempname, string op, varNode node1, varNode node2)
{
	string result = tempname + " = ";

	if (node1.num < 0)
	{
		result += node1.name;
	}
	else
		result += "var" + inttostr(node1.num);

	result += " " + op + " ";

	if (node2.num < 0)
	{
		result += node2.name;
	}
	else
		result += "var" + inttostr(node2.num);

	return result;
}



void Praser::error(int line, string error) {
	cout << "line:" << line << "[Error] "<<error << endl;
	exit(1);
}