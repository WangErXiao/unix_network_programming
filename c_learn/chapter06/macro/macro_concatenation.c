#include <stdio.h>

#define COMMAND(NAME) { #NAME,NAME ##_command}

struct command{
	char *name;
	void (*function)(void);
};

typedef struct command command;

void quit_command(){
	printf("quit command\n");
}
void help_command(){
	printf("help command\n");
}
int main(){
	command commands[]={
		COMMAND (quit),
		COMMAND (help)
	};
	int length=sizeof(commands)/sizeof(command);	
	for(int i=0;i<length;i++){
		printf("command name is %s\n",commands[i].name);
		commands[i].function();
	}
	return 0;
}
