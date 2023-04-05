#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>


int main(int argc, char **argv)
{
	char	*line;
	int		fd1;
    int     fd2;
    int     fd3;
    int     i;

    i = 1;
    if (argc >= 2)
    {
        
        while (i < argc)
        {
            fd1 = open (argv[i], O_RDONLY);
            line = get_next_line(fd1);
            printf("line [%02d]: %s", i, line);
            printf("%s", "\n");
            free(line);
            i++;
            close (fd1);
        }
    }
    else
    {
        fd1 = open("test1.txt", O_RDONLY);
        fd2 = open("test2.txt", O_RDONLY);
	    fd3 = open("test3.txt", O_RDONLY);
        while (i < 10)
        {   
	    	line = get_next_line(fd1);
	    	printf("line [%02d]: %s", i, line);
		    free(line);
            printf("%s", "\n");
            line = get_next_line(fd2);
	    	printf("line [%02d]: %s", i, line);
		    free(line);
            printf("%s", "\n"); 
            line = get_next_line(fd3);
	    	printf("line [%02d]: %s", i, line);
		    free(line);
            printf("%s", "\n");     
            i++;
        }
        close(fd1);
        close(fd2);
        close(fd3);
    }   
	return (0);
}