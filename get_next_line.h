/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:52:08 by msaadidi          #+#    #+#             */
/*   Updated: 2023/11/29 15:08:52 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t num_elements, size_t element_size);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);
void	*ft_memcpy(void *dest, void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memset(void *s, int c, size_t n);
char	*read_file(int fd, char *container);
char	*gget_line(char *container);
char	*update_container(char *container);

#endif
