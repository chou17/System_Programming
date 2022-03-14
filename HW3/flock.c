#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 4096

int main(int argc, char **argv)
{
    int flockDbFd;
    char buf[BUF_SIZE];
    int off;

    flockDbFd = open("./flock.db", O_RDWR | S_IRUSR｜S_IWUSR);
    for (int i = 0; i < 1000; i++)
    {
        flock(flockDbFd,LOCK_EX);
        lseek(flockDbFd, 0, SEEK_END);
        lseek(flockDbFd, -5, SEEK_CUR);
        read(flockDbFd, buf, 5);
        sscanf(buf, "%d", &off);
        lseek(flockDbFd, 0, SEEK_END);
        lseek(flockDbFd, off, SEEK_CUR);
        off++;
        sprintf(buf, "%d", off);
        write(flockDbFd, buf, 5);
        flock(flockDbFd,LOCK_UN);
        usleep(10000);
    }
}
