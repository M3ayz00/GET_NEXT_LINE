/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:53:15 by msaadidi          #+#    #+#             */
/*   Updated: 2023/11/29 15:08:21 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}

char	*ft_strchr(char *str, int c)
{
	while (str && *str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == '\0' && (char)c == '\0')
		return (str);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;
	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!src && !dest)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	str_len;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	str_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)ft_calloc(str_len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, ft_strlen(s1));
	ft_memcpy((new_str + ft_strlen(s1)), s2, ft_strlen(s2));
	free(s1);
	return (new_str);
}
