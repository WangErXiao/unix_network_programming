#include <stdio.h>

#define func(...) myfunc((struct mystru){__VA_ARGS__})


struct mystru { const char* name;int number; };

void myfunc(struct mystru ms){
	printf("%s:%d\n",ms.name?:"untitled",ms.number);
}

int main(int argc,char **argv){
	func("three",3);
	func(.number=100);
	func(.name="zero");
	return 0;
}
