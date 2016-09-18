#include <stdio.h>
#include <ctype.h>
#define MAXSIZE 100
#define MAXWORD 100
struct tnode{
	char *str[MAXSIZE];
	struct tnode *pleft;
	struct tnode *pright;
}
struct tnode *addtree(char *word,struct tnode *root){

}
void tprint(struct tnode *root){

}
char word[MAXWORD];
int getword(char *word,int lim){
	
}
int strcmp(char *w1,char *w2,int n){

}
int main(int argc,char *argv[]){
	int c;
	struct tnode *root;
	while((c=getword(word,MAXWORD))!=EOF){
		root = addtree(word,root);
	}
	tprint(root);
	return 0;
}
