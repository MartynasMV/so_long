/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoldema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:56:45 by mvoldema          #+#    #+#             */
/*   Updated: 2023/03/10 14:56:47 by mvoldema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_checker_left_right(t_map *main)
{
	int	y;
	int	z;
	int	q;

	y = 0;
	z = 0;
	q = 0;
	while (main->map && main->map[y])
	{
		if (main->map && main->map[y][0] == '1')
			z++;
		if (main->map && main->map[y][main->xlines - 1] == '1')
			q++;
		y++;
	}
	if (z != main->ycolumns || q != main->ycolumns)
	{
		ft_printf("Error\nLeft/right wall missing\n");
		free_double_array(main->map);
		exit(1);
	}
}

void	check_for_collectibles(t_map *main, char c)
{
	int	x;
	int	y;
	int	z;

	y = 0;
	x = 0;
	z = 0;
	while (main->map && main->map[y])
	{
		x = 0;
		while (main->map && (main->map[y][x] != '\n'
			&& main->map[y][x] != '\0'))
		{
			if (main->map[y][x] == c)
				z++;
			x++;
		}
		y++;
	}
	if (z < 1)
	{
		ft_printf("Error\nToo little collectibles\n");
		free_double_array(main->map);
		exit(1);
	}
}

void	check_for_forbidden_characters_part_2(t_map *main)
{
	if ((main->collectibles_count + main->player_count + main->ones_count
			+ main->zero_count + main->exit_count) != main->ycolumns
		* main->xlines || main->player_count != 1
		|| main->collectibles_count < 1 || main->exit_count != 1)
	{
		ft_printf("Error\nInvalid map. Char/P/E/C error\n");
		free_double_array(main->map);
		exit(1);
	}
}

void	check_for_forbidden_characters(t_map *main)
{
	int	y;
	int	x;

	y = 0;
	while (main->map && main->map[y])
	{
		x = 0;
		while (main->map && main->map[y][x] != '\0')
		{
			if (main->map[y][x] == 'C')
				main->collectibles_count++;
			else if (main->map[y][x] == 'P')
				main->player_count++;
			else if (main->map[y][x] == '1')
				main->ones_count++;
			else if (main->map[y][x] == '0')
				main->zero_count++;
			else if (main->map[y][x] == 'E')
				main->exit_count++;
			x++;
		}
		y++;
	}
	check_for_forbidden_characters_part_2(main);
}

void	check_player_xy_position(t_map *main)
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
			if (main->map[y][x] == 'P')
			{
				main->p_x = x;
				main->p_y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}
