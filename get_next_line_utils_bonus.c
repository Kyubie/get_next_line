/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:57:16 by grannou           #+#    #+#             */
/*   Updated: 2021/02/24 10:59:01 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
** returns 1 if newline character found in string, 0 otherwise
*/

int		ft_has_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

/*
** returns newline character's index in string if found, 0 otherwise
*/

int		ft_find_newline_index(char *str)
{
	int		index;

	index = 0;
	if (!str)
		return (0);
	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	return (index);
}

/*
** returns the length of the string, 0 if empty or non existent
*/

int		ft_strlen(const char *s)
{
	int		count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
		count++;
	return (count);
}

/*
** return the null terminated string result of the concatenation of s1 and s2
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_string;
	int		i;

	i = 0;
	joined_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!joined_string)
		return (NULL);
	while (s1 && *s1)
		joined_string[i++] = *s1++;
	while (s2 && *s2)
		joined_string[i++] = *s2++;
	joined_string[i] = '\0';
	return (joined_string);
}
