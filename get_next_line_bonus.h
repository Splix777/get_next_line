#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char    *get_next_line(int fd);
char    *ft_read_and_save(int fd, char *save);
char    *read_line(char *save);
char    *new_line(char *save);

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *str, char c);

size_t	ft_strlen(char *str);

#endif