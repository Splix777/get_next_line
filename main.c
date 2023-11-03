#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char	*line;
	int		fd1;
    int     i;

    i = 1;
    if (argc == 2)
    {
        fd1 = open (argv[1], O_RDONLY);
        line = get_next_line(fd1);
        while (line)
        {
            printf("line [%02d]: %s", i, line);
            free(line);
            printf("%s", "\n");
            i++;
            line = get_next_line(fd1);
        }
        for (int i = 0; i < 5; i++)
        {
            line = get_next_line(fd1);
            printf("line [%02d]: %s", i, line);
            free(line);
            printf("%s", "\n");
        }
        close (fd1);
    }
    else
    {
        fd1 = open("test1.txt", O_RDONLY);
        while (i < 10)
        {   
	    	line = get_next_line(fd1);
	    	printf("line [%02d]: %s", i, line);
		    free(line);
            printf("%s", "\n");      
            i++;
        }
        close(fd1);
    }   
	return (0);
}