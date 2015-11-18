/*************************************************************************
	> File Name: dp1.c
	> Author: yjwang
	> Mail: wyjss08@gmail.com 
	> Created Time: 2015年11月18日 星期三 20时35分03秒
 ************************************************************************/

#include<stdio.h>
int p[] = {0,1,5,8,9,10,17,17,20,24,30};
int MEMOIZED_CUT_ROD(int,int[],int[]);
int MEMOIZED_CUT(int n, int p[]){
	int r[n+1];
	int i;
	for(i=0;i<=n;++i){
		r[i] = -1;
	}
	return MEMOIZED_CUT_ROD(n,p,r);
}
int MEMOIZED_CUT_ROD(int n, int p[],int r[]){
	if(r[n]>0){
		return r[n];
	}
	int q = -1,i,s;
	if(n == 0){
		q = 0;
	}else{
		for(i=1;i<=n;++i){
			s = p[i] + MEMOIZED_CUT_ROD(n-i,p,r);
			if(q<s){
				q = s;
			}
		}
	}
	r[n] = q;
	return q;
}

int main(){
	int n,s;
	printf("Enter number:\n");
	scanf("%d",&n);
	s = MEMOIZED_CUT(n,p);
	printf("Max_Value is %d",s);
	return 0;
}
