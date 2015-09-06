#include <stdio.h>

int str_len(char *s);

int main(){
	printf("please input a string:\n");
	char *s;
	scanf("%s",s);
	printf("the length of s is:%d\n",str_len(s) );
	return 0;
}

int str_len(char *s){
	int n;
	for (n=0; *s !='\0';s++)
		n++;
	return n;
}

