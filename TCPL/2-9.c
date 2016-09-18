#include <stdio.h>
int bitcount(unsigned x){
	int b=0;
	while(x){
		b++;
		x&=(x-1);
	}
}
