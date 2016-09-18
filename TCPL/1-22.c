#还未解决
#include <stdio.h>
#define N 5
#define MAXSIZE 100
int main(){
	int c,count=0,temp=0,i;
	while((c=getchar())!=EOF){
		if(count<N&&c!=' '){
			putchar(c);
			for(i=0;i<temp;++i)putchar(' ');
			temp=0;
			++count;
		}else if(count<N&&c==' '){
			++count;
			++temp;
		}else if(count>=N&&c!=' '){
			putchar('\n');
			for(i=0;i<temp;++i)putchar(' ');
			if(temp<N)putchar(c);
			temp=0;
			count=0;
		}else if(count>=N&&c==' '){
			putchar('\n');
			for(i=0;i<temp;++i)putchar(' ');
			temp=1;
			count=0;
		}
	}
}
