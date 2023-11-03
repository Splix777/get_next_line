/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:02:41 by fsalazar          #+#    #+#             */
/*   Updated: 2023/03/24 13:02:42 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	index;
	size_t	i;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	joined = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!joined)
		free_and_return_null(s1);
	index = 0;
	i = 0;
	while (s1[i] != '\0')
		joined[index++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		joined[index++] = s2[i++];
	joined[index] = '\0';
	free(s1);
	return (joined);
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

char	*ft_strdup(char *s1)
{
	char	*rtn;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	rtn = malloc(sizeof(char) * len + 1);
	if (!rtn)
		return (NULL);
	while (s1[i])
	{
		rtn[i] = s1[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

char	*free_and_return_null(char *save)
{
	if (save)
		free(save);
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