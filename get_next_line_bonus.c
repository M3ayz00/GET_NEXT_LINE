/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:41:08 by msaadidi          #+#    #+#             */
/*   Updated: 2023/12/24 17:57:14 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*a;

	a = malloc(num_elements * element_size);
	if (!a)
		return (NULL);
	if (num_elements == 0 || element_size == 0)
	{
		ft_memset(a, 0, 1);
		return (a);
	}
	ft_memset(a, 0, element_size * num_elements);
	return (a);
}

char	*update_container(char *container)
{
	char	*updated;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (container[i] && container[i] != '\n')
		i++;
	if (!container[i])
	{
		free(container);
		return (NULL);
	}
	updated = (char *)ft_calloc(ft_strlen(container) - i + 1, sizeof(char));
	if (!updated)
	{
		free(container);
		return (NULL);
	}
	i++;
	while (container[i])
		updated[j++] = container[i++];
	free(container);
	return (updated);
}

char	*gget_line(char *container)
{
	char	*line;
	int		i;
	int		end;

	i = 0;
	if (!container[i])
		return (NULL);
	while (container[i] && container[i] != '\n')
		i++;
	if (container[i] == '\n')
		end = 2;
	else
		end = 1;
	line = (char *)ft_calloc(i + end, sizeof(char));
	if (!line)
		return (NULL);
	ft_memcpy(line, container, i);
	if (*(container + i) == '\n')
		*(line + i) = '\n';
	return (line);
}

char	*read_file(int fd, char *container)
{
	char	*buffer;
	int		readed;

	if (!container)
		container = ft_calloc(1, 1);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	readed = 1;
	while (!ft_strchr(container, '\n') && readed >= 1)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			free(container);
			return (NULL);
		}
		buffer[readed] = 0;
		container = ft_strjoin(container, buffer);
	}
	free(buffer);
	return (container);
}

char	*get_next_line(int fd)
{
	static char	*container[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	container[fd] = read_file(fd, container[fd]);
	if (!container[fd])
		return (NULL);
	line = gget_line(container[fd]);
	container[fd] = update_container(container[fd]);
	return (line);
}

int main()
{
	int fd1 = open("text1.txt",O_CREAT | O_RDWR);
    int fd2 = open("text2.txt",O_CREAT | O_RDWR);
    int fd3 = open("text3.txt",O_CREAT | O_RDWR);
	printf("%s\n", get_next_line(fd1));
	printf("%s\n", get_next_line(fd2));
	printf("%s\n", get_next_line(fd3));
	printf("%s\n", get_next_line(fd1));
	printf("%s\n", get_next_line(fd2));
	printf("%s\n", get_next_line(fd3));
	printf("%s\n", get_next_line(fd1));
	printf("%s\n", get_next_line(fd2));
	printf("%s\n", get_next_line(fd3));

}
