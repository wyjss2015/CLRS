#include <stdio.h>

int main(){
	printf("unsigned char is %u\n",(unsigned char)~0);
	printf("unsigned short is %u\n",(unsigned short)~0);
	printf("unsigned int is %u\n",(unsigned int)~0);
	printf("unsigned long is %lu\n",(unsigned long)~0);

	printf("max signed char is %d\n",(char)((unsigned char)~0>>1));
	printf("min signed char is %d\n",-(char)((unsigned char)~0>>1)-1);
	printf("min signed char is %d\n",(char)((unsigned char)~0<<7));
	return 0;
}
