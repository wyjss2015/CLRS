#include <stdio.h>
#include <ctype.h>
#define MAXSIZE 100
double stack[MAXSIZE];
int top=-1;
void push(double e){
	if(top==MAXSIZE)
		printf("error:stack is full!");
	else{
		stack[++top]=e;
		printf("%f\n",stack[top]);
		}
}
double pop(){
	if(top==-1)
		printf("error:stack is empty!");
	else
		return stack[top--];
}
double atof(char *s){
	int sign,power;
	double val;
	sign=(s[0]=='-')?-1:1;
	if(s[0]=='-'||s[0]=='+')
		s++;
	for(val=0.0;isdigit(*s);s++){
		val=val*10.0+*s-'0';
	}
	if(*s=='.'){
		s++;
		for(power=1;isdigit(*s);s++)
			val=val*10.0+*s-'0';
			power *= 10;
		return sign*val/power;
	}
	//printf("%f\n",sign*val);
	return sign*val;
}
int main(int argc,char *argv[]){
	while(--argc>0){
		switch((*++argv)[0]){
			case '+':
				push(pop()+pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			default:
				push(atof(*argv));
				break;
		}
	}
	printf("%f\n",pop());
	return 0;
}
