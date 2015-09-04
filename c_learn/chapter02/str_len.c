#include <stdio.h>

int str_len(char s[]);
int main(){
	printf("\r\n\"hello world\" 's length is %d \r\n", str_len("hello world"));
	return 0;
}

int str_len(char s[]){
	int i;
	while (s[i] !='\0')
		++i;
	return i;
}
