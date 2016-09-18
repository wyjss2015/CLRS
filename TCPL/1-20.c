#include <stdio.h>
#define N 8
void detab(){
	int c,i;
	while((c=getchar())!=EOF){
		if(c=='\t'){
			for(i=0;i<N;++i)putchar(' ');
		}else putchar(c);
	}
}	
int main(){
	detab();
	return 0;
}
