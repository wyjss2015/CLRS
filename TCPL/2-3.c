#include <stdio.h>
int htoi(char s[]){
	int i,n=0;
	for(i=2;s[i]!='\0';++i){
		if(s[i]>='0'&&s[i]<='9')n = n*16+s[i]-'0';
		else n = n*16+10+s[i]-'a';
	}
	return n;
}
int main(){
	char s[] = "0x1a";
	int n;
	n = htoi(s);
	printf("%d\n",n);
	return 0;
}
