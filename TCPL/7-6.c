#include <stdio.h>
#include <string.h>
#define LINEMAX 100
main(int argc,char *argv[]){
	FILE *f1,*f2;
	char line1[LINEMAX],line2[LINEMAX];
	f1 = fopen(argv[1],"r");
	f2 = fopen(argv[2],"r");
	while(fgets(line1,LINEMAX,f1)!=NULL&&fgets(line2,LINEMAX,f2)!=NULL){
		if(strcmp(line1,line2)!=0)
			break;
	}
	printf("%s%s",line1,line2);
	fclose(f1);
	fclose(f2);
	return 0;
}
