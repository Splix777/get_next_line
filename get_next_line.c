#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char        *line;
    static char *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = ft_read(fd, buffer);
    if (!buffer)
        return (NULL);
    line = ft_line(buffer);
    buffer = ft_buffer(buffer);
    return (line);
}

char    *ft_read(int fd, char *buffer)
{
    char    *buf;
    int     read_bytes;

    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);
    read_bytes = 1;
    while (!ft_strchr(buffer, '\n') && read_bytes != 0)
    {
        read_bytes = read(fd, buf, BUFFER_SIZE);
        if (read_bytes == -1)
        {
            free(buf);
            return (NULL);
        }
        buf[read_bytes] = '\0';
        buffer = ft_strjoin(buffer, buf);
    }
    free(buf);
    return (buffer);
    
}

char    *ft_line(char *buffer)
{
    char    *line;
    int     i;

    i = 0;
    while (buffer[i] != '\n' && buffer[i] != '\0')
        i++;
    line = malloc(sizeof(char) * (i + 1));
    if (!line)
        return (NULL);
    i = 0;
    while (buffer[i] != '\n' && buffer[i] != '\0')
    {
        line[i] = buffer[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

char    *ft_buffer(char *buffer)
{
    char    *temp;
    int     i;
    int     j;

    i = 0;
    while (buffer[i] != '\n' && buffer[i] != '\0')
        i++;
    if (buffer[i] == '\0')
    {
        free(buffer);
        return (NULL);
    }
    temp = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
    if (!temp)
        return (NULL);
    i++;
    j = 0;
    while (buffer[i] != '\0')
        temp[j++] = buffer[i++];
    temp[j] = '\0';
    free(buffer);
    return (temp);
}

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/