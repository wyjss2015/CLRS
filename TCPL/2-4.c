#include <stdio.h>
void squeeze(char s1[],char s2[]){
	int i,j,k,flag;
	for(i=0,j=0;s1[i]!='\0';++i){
		flag = 0;
		for(k=0;s2[k]!='\0';++k){
			if(s2[k]==s1[i])flag = 1;
		}
		if(flag==0){
			s1[j++]=s1[i];
		}
	}
	s1[j]='\0';
}
int main(){
	char s1[]="adfgereg";
	char s2[]="fg";
	int i;
	squeeze(s1,s2);
	for(i=0;s1[i]!='\0';++i){
		putchar(s1[i]);
	}
	return 0;
}
