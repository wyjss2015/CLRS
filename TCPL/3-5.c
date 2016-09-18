#include <stdio.h>
#include <string.h>
#define abs(x) ((x)<0?-(x):(x))
void reverse(char s[]){
	int i,j;
	char temp;
	for(i=0,j=strlen(s)-1;i<j;++i,--j){
		temp = s[i];
		s[i]=s[j];
		s[j]=temp;
	}
}
void itob(int n,char s[],int b){
	int i,sign;
	sign = n;
	i=0;
	do{
		s[i++]=(abs(n%b)<10)?abs(n%b)+'0':abs(n%b)-10+'a';
	}while((n/=b)!=0);
	if(sign<0)
		s[i++]='-';
	s[i]='\0';
	reverse(s);
}
int main(){
	int n = 14,b = 16;
	char s[60];
	int i;
	itob(n,s,b);
	for(i=0;s[i]!='\0';++i)putchar(s[i]);
	return 0;
}
