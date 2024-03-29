/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:02:07 by fsalazar          #+#    #+#             */
/*   Updated: 2023/03/24 13:03:30 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_and_save(int fd, char *save)
{
	char	*buffer;
	int		bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free_and_return_null(save));
	bytes = 1;
	while (!ft_strchr(save, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (free_and_return_null(save));
		}
		buffer[bytes] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*read_line(char *save)
{
	int		i;
	char	*temp;

	i = 0;
	if (save[i] == '\0' || !save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	temp = malloc((i + 1) * sizeof(char));
	if (!temp)
		return (free_and_return_null(save));
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		temp[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		temp[i] = save[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*new_save(char *save)
{
	int		i;
	int		index;
	char	*new;

	index = 0;
	while (save[index] && save[index] != '\n')
		index++;
	if (save[index] == '\0')
		return (free_and_return_null(save));
	new = malloc((ft_strlen(save) - index + 1) * sizeof(char));
	if (!new)
		return (free_and_return_null(save));
	index++;
	i = 0;
	while (save[index])
		new[i++] = save[index++];
	new[i] = '\0';
	free(save);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = read_line(save);
	save = new_save(save);
	return (line);
}
