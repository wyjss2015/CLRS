#include <stdio.h>
void lower(char s[]){
	int i;
	for(i=0;s[i]!='\0';++i){
		(s[i]>='A'&&s[i]<='Z')?s[i]=s[i]-'A'+'a':s[i]=s[i];
	}
}
int main(){
	char s[]="dsfFSDFdsFDSd";
	int i;
	lower(s);
	for(i=0;s[i]!='\0';++i)putchar(s[i]);
	return 0;
}
