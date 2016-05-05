#include <stdio.h>
#include <stdlib.h>

#define COMMAND(NAME) { #NAME, NAME ##     _command } 

void quit_command(){}
void help_command(){}

struct command { 
    char *name; 
    void (*function) (void); 
};

struct command commands[] = { 
    COMMAND (quit),
    COMMAND (help)
};

int main()
{
	printf("What??!");
	return 0;
}