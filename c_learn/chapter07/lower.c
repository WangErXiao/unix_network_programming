#include <stdio.h>
#include <ctype.h>

int main(){
	putchar('t');
	putchar('e');
	putchar('s');
	putchar('t');
	int c;
	while((c=getchar())!=EOF)
		putchar(tolower(c));
	return 0;
}
