#include <stdlib.h> 
#include <stdbool.h> 
#include <stdio.h> 
#include <string.h> 
static bool logged = false;
int main(int argc, char *argv[]) {
	for (unsigned i=1;i<argc && !logged;++i) {
		if (logged = !strcmp(argv[i], "0xDEADBEEF")) {
			printf("Logged in\n");
		}
	}
	return 0;
}