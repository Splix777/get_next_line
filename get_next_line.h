#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

char    *get_next_line(int fd);
char    *ft_read(int fd, char *buffer);
char    *ft_line(char *buffer);
char    *ft_buffer(char *buffer);
char    *ft_strdup(const char *s1);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char const *s1, char const *s2);

int     ft_strlen(char *str);

void    *ft_memcpy(void *restrict dest, const void *restrict src, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t n);

#endif