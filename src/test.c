int fib(int n)
{
	int ans;
	if(n==1){
		ans=1;
	}else if(n==2){
		ans=1;
	}
	else{
		ans=fib(n-1)+fib(n-2);
	}
	return ans;
	
}

int main()
{
	int a,v;
	a=scan();  //从键盘中读入一个数
	v=fib(a);
	print(v);
	return 0;
}
