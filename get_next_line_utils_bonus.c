#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	index;
	size_t	i;
	char	*joined;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	joined = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	index = 0;
	i = 0;
	while (s1[i] != '\0')
		joined[index++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		joined[index++] = s2[i++];
	joined[index] = '\0';
	return (joined);
}

char	*ft_strdup(char *s1)
{
	char	*new;
	size_t	i;

	if (!s1)
		return (NULL);
	new = malloc((ft_strlen(s1) + 1) * sizeof(char));
	i = 0;
	while(s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
