#include <string.h>
#include <stdio.h>

// hard coded jmp *esp function ;-)
void jmpesp()
{
    __asm__("jmpq *%rax");
}

int main(int argc, char *argv[])
{
    char buffer[100];
    strcpy(buffer, argv[1]);
    printf("buffer: [%s].\n", buffer);
    return 0;
}