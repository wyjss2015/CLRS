#include <stdio.h>
void escape(char s[],char t[]){
	int i,j;
	for(i=0,j=0;t[j]!='\0';++j){
		switch(t[j]){
			case '\n':
				s[i++]='\\';
				s[i++]='n';
				break;
			case '\t':
				s[i++]='\\';
				s[i++]='t';
				break;
			default:
				s[i++]=t[j];
				break;
		}
	}
	s[i]='\0';
}
int main(){
	char t[]="fds	fs\ndf\tdsfd";
	char s[50];
	int i;
	escape(s,t);
	for(i=0;s[i]!='\0';++i){
		putchar(s[i]);
	}
	return 0;
}
