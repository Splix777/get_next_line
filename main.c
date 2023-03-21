#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char    *get_next_line_bonus(int fd);

int main(void)
{
    int fd;
    int fd2;
    char *line;


    fd = open("test.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
    while(line = get_next_line(fd))
    {
        printf("%s", line);
    }
    while(line = get_next_line(fd2))
    {
        printf("%s", line);
    }
    close(fd);
    return (0);
}
