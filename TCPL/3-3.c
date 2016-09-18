#include <stdio.h>
void expand(char s1[],char s2[]){
	int i,j;
	char k;
	for(i=0,j=0;s1[i]!='\0';++i){
		if(s1[i]=='-'){
			if(i==0)s2[j++]=s1[i];
			else if(s1[i+1]-s1[i-1]==1)s2[j++]=s1[i];
			else
				for(k=s1[i-1]+1;k<s1[i+1];k++)s2[j++]=k;
		}else
			s2[j++]=s1[i];
	}
	s2[j]='\0';
}
int main(){
	char t[]="a-z0-9";
	char s[50];
	int i;
	expand(t,s);
	for(i=0;s[i]!='\0';++i)putchar(s[i]);
	return 0;
}
