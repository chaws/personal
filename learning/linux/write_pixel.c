#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
    int y = 500, x = 500, fd, ret;
    fd = open("/dev/fb0", O_RDWR);
    if(fd < 0)
    {
        perror("Can't open file");
        return fd;
    }

    if((ret = lseek(fd, 640*y+x, SEEK_SET)) == -1)
    {
        perror("Can't move cursor");
        return ret;
    }

    if((ret = write(fd, "\377\377\377\377", 4)) == -1)
    {
        perror("Can't write to monitor");
        return ret;
    }

    return 0;
}
