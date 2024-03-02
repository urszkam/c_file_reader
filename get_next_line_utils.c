/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:25:45 by ukaminsk          #+#    #+#             */
/*   Updated: 2024/02/26 17:34:29 by ukaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;
	char	*dest;

	s_len = ft_strlen(s);
	if (start > s_len)
		d_len = 0;
	else if (s_len - start > len)
		d_len = len;
	else
		d_len = s_len - start;
	dest = (char *) malloc((d_len + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (i < d_len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			j;
	char	*dest;

	dest = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	j = -1;
	while (s2[++j])
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strndup(char *str, int n)
{
	char	*new;
	int			i;

	new = (char *) malloc((n + 1) * sizeof(char));
	if (!new)
		return (0);
	i = 0;
	while (str[i] && i < n)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}
