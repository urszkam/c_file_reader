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

Ensure that the function works seamlessly for both file reading and standard input.
*/

#include "get_next_line.h"

static void	putstr(char *str)
{
	write(1, str, strlen(str));
}

static char	find_line(char *str, static char *remainder)
{
	int			position;
	char	*sub;
	char	*line;
	
	position = ft_strchr(str, '\n') - str;
	sub = ft_substr(str, 0, position);
	line = ft_strjoin(remainder, sub);
	free(sub);
	return (line);
}

static char	*get_next_line(int fd)
{
	int			bytes;
	char	*str;
	char	*line;
	static char	*remainder;

	remainder = "";
	if (fd == -1 || BUFF_SIZE <= 0)
		return (0);
	str = (char *) malloc((BUFF_SIZE + 1) * sizeof(char));
	if (!str)
		return (0);
	//Getting x number of chas
	while (!ft_strchr(str, '\n'))
	{
		bytes = read(fd, str, BUFF_SIZE);
		if (bytes == -1)
			return (0);
		str[bytes] = 0;
		remainder = 
	//Checking if there is
	}
	line = ft_strjoin(remainder, ft_substr(str, 0, ft_strchr(str, \n) - str));
	return (line);
}

int	main(void) {

	return (0);
}
