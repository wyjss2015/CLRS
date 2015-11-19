/*************************************************************************
	> File Name: test1-5.c
	> Author: yjwang
	> Mail: wyjss08@gmail.com 
	> Created Time: 2015年11月19日 星期四 16时30分51秒
 ************************************************************************/

#include<stdio.h>
//FIRST:UP_DOWN RECURSION METHOD
/*
int Fibonacci(int n, int F[]){
	if(F[n]>=0)return F[n];
	int x;
	if(n == 0) x = 0;
	if(n == 1) x = 1;
	else{
		x = Fibonacci(n-1,F) + Fibonacci(n-2,F);
	}
	F[n] = x;
	return x;
}*/
//SECOND:DOWN_UP METHOD
int Fibonacci(int n){
	int F[n+1],i;
	F[0] = 0;
	F[1] = 1;
	for(i=2;i<=n;++i){
		F[i] = F[i-1]+F[i-2];
	}
	return F[n];
}
int main(){
	int n,s,i;
	printf("enter number:");
	scanf("%d",&n);
	int F[n+1];
	F[0] = 0;
	F[1] = 1;
	for(i=2;i<=n;++i){
		F[i] = -1;
	}
	s = Fibonacci(n,F);
	printf("Fibonacci(%d) is %d",n,s);
	return 0;
}
