/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:46:34 by marcofer          #+#    #+#             */
/*   Updated: 2023/11/05 20:02:28 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (0);
	if (c == '\0')
		return (str + ft_strlen(str));
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*new_str;
	int		i;
	int		j;

	i = ft_strlen(str1) + ft_strlen(str2);
	new_str = malloc(sizeof(char) * (i + 1));
	if (!new_str)
		return (0);
	i = 0;
	if (str1)
	{
		while (str1[i] != 0)
		{
			new_str[i] = str1[i];
			i++;
		}
	}
	j = 0;
	while (str2[j] != '\0')
		new_str[i++] = str2[j++];
	new_str[i] = '\0';
	free(str1);
	return (new_str);
}

char	*ft_get_line(char *str)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	if (!str[len])
		return (NULL);
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_str(char *str)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new)
		return (NULL);
	j = 0;
	i++;
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	free(str);
	return (new);
}

char	*ft_read_to_str(int fd, char *str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_to_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_new_str(str);
	return (line);
}

#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int	main(void)
{
	// Test get_next_line
		int		fd1;
		int		i;
		char	*line;

		fd1 = open("tests/test.txt", O_RDONLY);

		i = 1;
		while (i < 10)
		{
			line = get_next_line(fd1);
			printf("\nline [%d]:\n %s", i, line);
			free(line);
			i++;
		}
		printf("\n--- END ---\n");
		close(fd1);
	return (0);
}