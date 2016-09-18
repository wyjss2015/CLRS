#include <stdio.h>
#include <ctype.h>
double atof(char s[]){
	int i,sign,power,flag,exp,k;
	double n;
	for(i=0;s[i]==' ';++i)
		;
	sign = (s[i]=='-')?-1:1;
	if(s[i]=='-'||s[i]=='+')
		i++;
	for(n=0.0;isdigit(s[i]);++i)
		n = 10.0*n+s[i]-'0';
	if(s[i]=='.')
		i++;
	for(power=1.0;isdigit(s[i]);++i){
		n = 10.0*n+s[i]-'0';
		power *= 10;
	}
	if(s[i]=='e'||s[i]=='E')
		flag = (s[++i]=='-')?-1:1;
	if(s[i]=='-'||s[i]=='+')
		i++;
	for(exp=0;isdigit(s[i]);++i)
		exp = 10*exp+s[i]-'0';
	if(flag==-1){
		for(k=0;k<exp;k++)
			power *= 10.0;
	}else{
		for(k=0;k<exp;k++)
			power /= 10.0;
	}
	return sign*n/power;
}
int main(){
	char s[]="123.45e-6";
	printf("%f",atof(s));
	return 0;
}
