/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:07:26 by ukaminsk          #+#    #+#             */
/*   Updated: 2024/03/04 20:07:29 by ukaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif
