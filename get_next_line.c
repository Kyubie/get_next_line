/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:24:18 by grannou           #+#    #+#             */
/*   Updated: 2021/02/24 10:57:59 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** return a string with all characters found before newline character
*/

char	*ft_get_before_newline(char *str)
{
	char	*line;
	int		i;
	int		newline_index;

	newline_index = ft_find_newline_index(str);
	line = malloc(sizeof(char) * newline_index + 1);
	if (!line)
		return (NULL);
	i = 0;
	if (str)
	{
		while (str[i] && str[i] != '\n')
		{
			line[i] = str[i];
			i++;
		}
	}
	line[i] = '\0';
	return (line);
}

/*
** return a string with all characters found after newline character
*/

char	*ft_get_after_newline(char *spare)
{
	int		newline_index;
	int		i;

	if (!spare)
		return (NULL);
	newline_index = ft_find_newline_index(spare);
	if (!spare[newline_index])
	{
		free(spare);
		return (NULL);
	}
	if (spare && spare[newline_index])
		newline_index++;
	i = 0;
	while (spare && spare[newline_index])
	{
		spare[i] = spare[newline_index];
		i++;
		newline_index++;
	}
	spare[i] = '\0';
	return (spare);
}

/*
** read a file and search for a line aka a newline terminated string
** returns 1 if a line as been read, 0 if EOF is reached, -1 if error
** copies line and save buffer's spare characters after newline in a static
** variable for next call of the function
*/

int		get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	char			*temp;
	static char		*spare;
	int				read_size;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || (read(fd, buffer, 0) == -1))
		return (-1);
	read_size = 1;
	while (!(ft_has_newline(spare))
			&& ((read_size = read(fd, buffer, BUFFER_SIZE))) != 0)
	{
		if (read_size == -1)
			return (-1);
		buffer[read_size] = '\0';
		temp = spare;
		spare = ft_strjoin(spare, buffer);
		free(temp);
	}
	*line = ft_get_before_newline(spare);
	spare = ft_get_after_newline(spare);
	if (read_size == 0)
		return (0);
	return (1);
}
