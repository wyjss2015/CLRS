/*************************************************************************
	> File Name: dp1.c
	> Author: yjwang
	> Mail: wyjss08@gmail.com 
	> Created Time: 2015年11月18日 星期三 20时35分03秒
 ************************************************************************/

#include<stdio.h>
int p[] = {0,1,5,8,9,10,17,17,20,24,30};
int MEMOIZED_CUT_ROD(int n,int p[],int r[],int trace[]);
int MEMOIZED_CUT(int n, int p[],int trace[]){
	int r[n+1];
	int i,j,s;
	for(i=0;i<=n;++i){
		r[i] = -1;
	}
	s = MEMOIZED_CUT_ROD(n,p,r,trace);
	return s;
}
int MEMOIZED_CUT_ROD(int n, int p[],int r[], int trace[]){
	if(r[n]>0){
		return r[n];
	}
	int q = -1,i,s,k;
	if(n == 0){
		q = 0;
		k = 0;
	}else{
		for(i=1;i<=n;++i){
			s = p[i] + MEMOIZED_CUT_ROD(n-i,p,r,trace);
			if(q<s){
				q = s;
				k = i;
			}
		}
	}
	r[n] = q;
	trace[n] = k;
	return q;
}

int main(){
	int n,s;
	printf("Enter number:\n");
	scanf("%d",&n);
	int trace[n+1],j;
	s = MEMOIZED_CUT(n,p,trace);
	printf("Max_Value is %d",s);
	//print trace
	j = n;
	printf("\n");
	while(j != 0){
		printf("%d ",trace[j]);
		j = j - trace[j];
	}
	printf("\n");
	return 0;
}
