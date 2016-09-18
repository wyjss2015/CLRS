#include <stdio.h>
void strcat(char *s,char *t){
	while(*s++)
		;
	s--;
	while(*s++=*t++)
		;
}
int main(){
	char s[20]={'n','i','h','a','o',',','\0'};
	char t[]="world!";
	char *p=s;
	strcat(s,t);
	while(*p){
		putchar(*p);
		p++;
	}
	return 0;
}
