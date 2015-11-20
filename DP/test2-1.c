/*************************************************************************
	> File Name: test2-1.c
	> Author: yjwang
	> Mail: wyjss08@gmail.com 
	> Created Time: 2015年11月20日 星期五 20时31分29秒
 ************************************************************************/

#include<stdio.h>
#define INT_MAX unsigned(-1)>>1			//定义无穷大
//求解矩阵链最优计算顺序，m存储值，s存储最优解
void Matrix_chain_order(int p[], int n, int m[][7], int s[][7]){
	int i,j,k,q;
	for(i=1;i<=n;i++){
		m[i][i] = 0;	
	}
	for(i=2;i<=n;i++){
		for(j=1;j<=n-i+1;j++){
			m[j][j+i-1] = INT_MAX;
			for(k=j;k<j+i;k++){
				q = m[j][k] + m[k+1][j+i-1] + p[j-1]*p[j+i-1]*p[k];
				if(q<m[j][j+i-1]){
					m[j][j+i-1] = q;
					s[j][j+i-1] = k;
				}
			}
		}
	}
}
//打印最优解
void Print_opimal(int s[][7], int i, int j){
	if(i == j){
		printf("A%d",i);
	}
	else{
		printf("(");
		Print_opimal(s,i,s[i][j]);
		Print_opimal(s,s[i][j]+1,j);
		printf(")");
	}
}
int main(){
	int p[] = {5,10,3,12,5,50,6};
	int n = 6;
	int m[7][7],s[7][7];
	int i,j;
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			m[i][j] = -1;
			s[i][j] = -1;
		}
	}
	Matrix_chain_order(p,n,m,s);
	printf("%d\n",m[1][n]);
	Print_opimal(s,1,n);
	return 0;
}
