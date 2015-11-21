/*************************************************************************
	> File Name: test2-2.c
	> Author: yjwang
	> Mail: wyjss08@gmail.com 
	> Created Time: 2015年11月21日 星期六 14时05分57秒
 ************************************************************************/

#include<stdio.h>
struct matrix {
	int rows;
	int columns;
	int matrix[rows][columns];
} *A[7];
struct matrix *Multiply(struct matrix *A[], int s[][7], int i, int j){
	int p,q,k;
	struct matrix *m1,*m2,*m3;
	if(i == j){
		return A[i];
	}else{
		m1 = Multiply(A,s,i,s[i][j]);
		m2 = Multiply(A,s,s[i][j]+1,j);
		for(p=0;p<m1->rows;++p){
			for(q=0;q<m2->columns;++q){
				m3->rows = m1->rows;
				m3->columns = m2->columns;
				m3->matrix[p][q] = 0;
				for(k=0;k<m1->columns;++k){
					m3->matrix[p][q] += m3->matrix[p][q] + m1->maxtrix[p][k]
						*m2->maxtrix[k][q];
				}
			}
		}
		return m3;
	}
}
