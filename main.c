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

#include "get_next_line.h"
#include "get_next_line_utils.c"
#include "get_next_line.c"

#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int	main(void)
{
	// Test strlen, strjoin, strchr
		/*
		char	str[] = "FC Porto";
		char	str1[] = "Ronaldo";
		char	str2[] = " is the GOAT";
		
		printf("%s\n", str);
		printf("%ld\n", ft_strlen(str));
		printf("%s\n", ft_strjoin(str1, str2));
		printf("%ld\n", ft_strlen(ft_strjoin(str1, str2)));
		printf("%s\n", ft_strchr(str, ' '));
		*/
	
	// Test get_line, new_left_str
		/*
		char	*str3;
		char	*line;
		
		str3 = (char *)malloc(sizeof(char) * 40);
		strncpy(str3, "Line1\nLine2\n\nLine4", 40);
		printf("\n Text:\n %s\n--------\n", str3);
		
		line = ft_get_line(str3);
		printf("\n Line 1: %s\n--------\n", line);
		
		str3 = ft_new_str(str3);
		line = ft_get_line(str3);
		printf("\n Line 2: %s\n--------\n", line);
		
		str3 = ft_new_str(str3);
		line = ft_get_line(str3);
		printf("\n Line 3: %s\n--------\n", line);

		str3 = ft_new_str(str3);
		line = ft_get_line(str3);
		printf("\n Line 4: %s\n--------\n", line);

		str3 = ft_new_str(str3);
		line = ft_get_line(str3);
		printf("\n Line 5: %s\n--------\n", line);
		*/

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