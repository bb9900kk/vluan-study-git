#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


int main()
{
    int fd;
    char * myfifo = "/tmp/myfifo";

    /* create the FIFO (named pipe) */
    printf("\n Starting create mkfifio file");
    mkfifo(myfifo, 0666); //This will delayed until have read request on this file happen
    printf("\n Created mkfifo file: DONE");

    /* write "Hi" to the FIFO */
    fd = open(myfifo, O_WRONLY);
    write(fd, "Hi", sizeof("Hi"));
    close(fd);

    /* remove the FIFO */
    unlink(myfifo);

printf("\n Exit program Writer \n");
    return 0;
}
