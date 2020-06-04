/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:26:51 by skarry            #+#    #+#             */
/*   Updated: 2020/06/04 14:00:32 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char	*line;
	int		fd1;
	int		fd2;
	int		fd3;
	int		a;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	a = 1;
	while ( a > 0)
	{
		a = get_next_line(fd1, &line);
		printf("line_main: |%s|\na: %d\n\n", line, a);
		free(line);
		line = NULL;
		if (a == 0)
			close(fd1);
		a = get_next_line(fd2, &line);
		printf("line_main: |%s|\na: %d\n\n", line, a);
		free(line);
		line = NULL;
		if (a == 0)
			close(fd2);
		a = get_next_line(fd3, &line);
		printf("line_main: |%s|\na: %d\n\n", line, a);
		free(line);
		line = NULL;
		if (a == 0)
			close(fd3);
	}
	if (a != 0)
		printf("a: %d\n\n", a);
	// getchar();
	return (0);
}
