int strcmp(char *s,char *t,int n){
	for(;*s==*t&&n>0;s++,t++,n--){
		if(*s=='\0')
			return 0;
	}
	if(n=0)
		return 0;
	else
		return *s-*t;
}
