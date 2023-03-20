#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*rtn;
	size_t	len;

	len = ft_strlen(s1) + 1;
	rtn = malloc(sizeof(char) * len);
	if (!rtn)
		return (0);
	rtn = ft_memcpy(rtn, s1, len);
	return (rtn);
}

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned char		*dest2;
	const unsigned char	*src2;
	size_t				a;

	dest2 = dest;
	src2 = src;
	a = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (a < n)
	{
		dest2[a] = src2[a];
		a++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;
	char	*joined;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len + 1;
	joined = malloc(sizeof(char) * total_len);
	if (!joined)
		return (0);
	ft_memmove(joined, s1, s1_len);
	ft_memmove(joined + s1_len, s2, s2_len);
	joined[total_len - 1] = '\0';
	return (joined);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest2;
	const char	*src2;

	dest2 = dest;
	src2 = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest2 <= src2 || dest2 >= (src2 + n))
	{
		while (n-- > 0)
			*dest2++ = *src2++;
	}
	else
	{
		dest2 += n;
		src2 += n;
		while (n-- > 0)
			*(--dest2) = *(--src2);
	}
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == uc)
			return ((char *)s);
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}
