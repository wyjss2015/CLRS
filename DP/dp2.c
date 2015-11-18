/*************************************************************************
	> File Name: dp2.c
	> Author: yjwang
	> Mail: wyjss08@gmail.com 
	> Created Time: 2015年11月18日 星期三 22时52分13秒
 ************************************************************************/

#include<stdio.h>
int p[] = {0,1,5,8,9,10,17,17,20,24,30};
int CUT_DOWN_ROD(int n, int p[]){
	int i,j,s,q;
	int r[n+1];
	r[0] = 0;
	for(i=1;i<=n;++i){
		r[i] = -1;
	}
	for(j=1;j<=n;++j){
		q = -1;
		for(i=1;i<=j;++i){
			s = p[i] + r[j-i];
			if(q<s){
				q = s;
			}
		}
		r[j] = q;
	}
	return r[n];
}
int main(){
	int n;
	printf("pls enter number: \n");
	scanf("%d",&n);
	printf("Max_Value is %d",CUT_DOWN_ROD(n,p));
	return 0;
}
