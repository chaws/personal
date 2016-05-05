#include <unistd.h>

int main(void)
{
    // double * ptr = 0, a;
    // a = *(ptr + 1);
    char * args[] = {NULL, NULL}, * envir[] = {NULL};
    execve("/bin/sh", 0, envir);
    return 0;
}
