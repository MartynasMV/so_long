/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoldema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:56:50 by mvoldema          #+#    #+#             */
/*   Updated: 2023/03/10 14:56:55 by mvoldema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit_xy_position(t_map *main)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (main->map && main->map[y])
	{
		x = 0;
		while (main->map && main->map[y][x] != '\0')
		{
			if (main->map[y][x] == 'E')
			{
				main->e_x = x;
				main->e_y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

void	temp_main_calloc(t_map *main, char *file_name)
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
	main->tmp = ft_calloc(main->ycolumns + 1, sizeof(char *));
	if (!main->tmp)
		free_double_array(main->map);
	while (i < main->ycolumns)
	{
		main->tmp[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	dfs(t_map *main, int y, int x)
{
	char	*current;

	current = &main->tmp[y][x];
	if (*current == 'E')
		return (1);
	if (*current == '0' || *current == 'C' || *current == 'P')
	{
		*current = 'X';
		if (dfs(main, y, x - 1) || dfs(main, y, x + 1) || dfs(main, y - 1, x)
			|| dfs(main, y + 1, x))
		{
			*current = 'X';
			return (1);
		}
	}
	return (0);
}

int	dfs_searching_for_collectible(t_map *main, int y, int x)
{
	char	*current;

	current = &main->tmp[y][x];
	if (*current == 'C')
		return (1);
	if (*current == '0' || *current == 'E' || *current == 'P')
	{
		*current = 'X';
		if (dfs_searching_for_collectible(main, y, x - 1)
			|| dfs_searching_for_collectible(main, y, x + 1)
			|| dfs_searching_for_collectible(main, y - 1, x)
			|| dfs_searching_for_collectible(main, y + 1, x))
		{
			*current = 'X';
			return (1);
		}
	}
	return (0);
}
