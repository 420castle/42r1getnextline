/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:36:19 by marcofer          #+#    #+#             */
/*   Updated: 2023/09/27 16:36:19 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "get_next_line_utils_bonus.c"
#include "get_next_line_bonus.c"

#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 10)
	{
		line = get_next_line(fd1);
		printf("\n--- LINE [%02d] ---", i);
		printf("\nFile 1: line %02d: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("\nFile 2: line %02d: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("\nFile 3: line %02d: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}