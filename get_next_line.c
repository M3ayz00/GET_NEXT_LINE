/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:51:18 by msaadidi          #+#    #+#             */
/*   Updated: 2023/11/29 15:28:13 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*a;

	if (num_elements != 0 && SIZE_MAX / num_elements < element_size)
		return (NULL);
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
	while (container[i++])
		updated[j++] = container[i];
	free(container);
	return (updated);
}

char	*get_line(char *container)
{
	char	*line;
	int		i;

	i = 0;
	while (container[i] && container[i] != '\n')
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	ft_memcpy(line, container, i);
	if (*(container + i + 1) == '\n')
		*(line + i + 1) = '\n';
	return (line);
}

char	*read_file(int fd, char *container)
{
	char	*buffer;
	int		readed;

	readed = 1;
	if (!container)
		container = ft_calloc(1, 1);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
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
	static char	*container;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	container = read_file(fd, container);
	if (!container)
		return (NULL);
	line = get_line(container);
	container = update_container(container);
	return (line);
}
int main()
{
	int fd = open("sbiskal.txt", O_RDONLY);
	char *awee = get_next_line(fd);

	while(awee)
	{
		printf("%s",get_next_line(fd));
		free(awee);
		awee=get_next_line(fd);
	}


}