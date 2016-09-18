#include <stdio.h>
int any(char s1[],char s2[]){
	int i,j;
	for(i=0;s1[i]!='\0';++i){
		for(j=0;s2[j]!='\0';++j){
			if(s2[j]==s1[i])return i;
		}
	}
	return -1;
}
int main(){
	char s1[]="adfwec";
	char s2[]="f";
	int pos;
	pos = any(s1,s2);
	printf("%d\n",pos);
	return 0;
}
