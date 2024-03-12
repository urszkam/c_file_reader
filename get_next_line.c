/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:07:16 by ukaminsk          #+#    #+#             */
/*   Updated: 2024/03/04 20:07:20 by ukaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Repeated calls to get_next_line should enable sequential reading 
of the text file pointed to by the file descriptor, 
processing one line at a time. The function returns the read line
or NULL if there is nothing else to read or if an error occurs.

Ensure that the function works seamlessly 
for both file reading and standard input.
*/

#include "get_next_line.h"

static char	*find_line(char **remainder)
{
	int		position;
	char	*temp;
	char	*line;

	if (!ft_strchr(*remainder, '\n'))
	{
		line = *remainder;
		*remainder = ft_strdup("");
	}
	else
	{
		pos = ft_strchr(*remainder, '\n') - *remainder;
		line = ft_substr(*remainder, 0, pos + 1);
		temp = *remainder;
		*remainder = ft_substr(temp, pos + 1, ft_strlen(temp) - (pos + 1));
		free(temp);
	}
	return (line);
}

static int	read_loop(int fd, char **remainder)
{
	int		bytes;
	char	*temp;
	char	*str;

	str = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (0);
	while (!ft_strchr(str, '\n'))
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes == -1 || bytes == 0)
			break ;
		str[bytes] = '\0';
		temp = *remainder;
		*remainder = ft_strjoin(temp, str);
		free(temp);
	}
	free(str);
	return (bytes > 0);
}

char	*get_next_line(int fd)
{
	int			bytes;
	char		*line;
	static char	*remainder;

	if (!remainder)
		remainder = ft_strdup("");
	if (fd <= -1 || BUFFER_SIZE <= 0)
	{
		free(remainder);
		return (0);
	}
	bytes = read_loop(fd, &remainder);
	if ((!bytes && !*remainder) || !remainder)
	{
		if (remainder)
		{
			free(remainder);
			remainder = NULL;
		}
		return (0);
	}
	line = find_line(&remainder);
	return (line);
}
