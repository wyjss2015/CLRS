#include <stdio.h>
#define N 8
void entab(){
	int c,count=0,flag=0,i,j;
	while((c=getchar())!=EOF){
		if(c==' '&&flag==0){
			flag=1;
			count=1;
		}else if(c==' '&&flag==1)++count;
		else{
			flag=0;
			for(i=count/N;i>0;--i)putchar('\t');
			for(i=count%N;i>0;--i)putchar(' ');
			count=0;
			putchar(c);
		}
	}
}
int main(){
	entab();
	return 0;
}
