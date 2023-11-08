/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoldema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:56:39 by mvoldema          #+#    #+#             */
/*   Updated: 2023/03/10 14:56:41 by mvoldema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	column_counter(t_map *main, char *file_name)
{
	int		fd;
	char	*main_column;

	main->ycolumns = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nOpen() error\n");
		exit(1);
	}
	main_column = get_next_line(fd);
	if (!main_column)
		exit(1);
	while (main_column != NULL)
	{
		free(main_column);
		main_column = NULL;
		main_column = get_next_line(fd);
		main->ycolumns++;
	}
	free(main_column);
	close(fd);
	return (main->ycolumns);
}

void	main_calloc_and_fill(t_map *main, char *file_name)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nOpen() error\n");
		exit(1);
	}
	main->map = ft_calloc(main->ycolumns + 1, sizeof(char *));
	while (i < main->ycolumns)
	{
		main->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	first_line_counter(t_map *main)
{
	int	i;

	i = 0;
	while (main->map && (main->map[0][i] != '\n' && main->map[0][i] != '\0'))
		i++;
	main->xlines = i;
}

void	horisontal_line_validator(t_map *main)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (main->map && main->map[y])
	{
		x = 0;
		while (main->map && (main->map[y][x] != '\n'
			&& main->map[y][x] != '\0'))
		{
			x++;
		}
		if (main->xlines != x)
		{
			ft_printf("Error\nSmth with lines\n");
			free_double_array(main->map);
			exit(1);
		}
		y++;
	}
}

void	wall_checker_top_bottom(t_map *main)
{
	int	x;
	int	q;

	x = 0;
	q = 0;
	while (main->map && (main->map[0][x] == '1'))
		x++;
	while (main->map && (main->map[main->ycolumns - 1][q] == '1'))
		q++;
	if (x != main->xlines || q != main->xlines)
	{
		ft_printf("Error\nTop/bottom wall is missing\n");
		free_double_array(main->map);
		exit(1);
	}
}
