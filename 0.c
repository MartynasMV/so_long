/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dot_ber.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoldema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:34:50 by mvoldema          #+#    #+#             */
/*   Updated: 2023/03/10 11:34:51 by mvoldema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_dot_ber(int ac, char **av)
{
	int		i;
	int		j;
	char	*extension;

	i = ft_strlen(av[1]) - 4;
	j = 0;
	extension = ".ber";
	if (ac != 2)
	{
		ft_printf("Error\nMap can't be read");
		exit(1);
	}
	while ((av[1][i] == extension[j]) && extension[j] != '\0')
	{
		i++;
		j++;
	}
	if (j != 4)
	{
		ft_printf("Error\nExtension is not supported.");
		exit(1);
	}
}

void	flood_fill(char **tmp, t_map main, t_path path, int *counter)
{
	if (path.y < 0 || path.y >= main.ycolumns || path.x < 0
		|| path.x >= main.xlines || (tmp[path.y][path.x] != '0'
		&& tmp[path.y][path.x] != 'C' && tmp[path.y][path.x] != 'E'
			&& tmp[path.y][path.x] != 'P'))
	{
		return ;
	}
	if (tmp[path.y][path.x] == 'C' || tmp[path.y][path.x] == 'E')
	{
		(*counter)++;
	}
	tmp[path.y][path.x] = '.';
	flood_fill(tmp, main, (t_path){path.x - 1, path.y}, counter);
	flood_fill(tmp, main, (t_path){path.x + 1, path.y}, counter);
	flood_fill(tmp, main, (t_path){path.x, path.y - 1}, counter);
	flood_fill(tmp, main, (t_path){path.x, path.y + 1}, counter);
}

int	pathfinder(t_map *main)
{
	t_path	s_path;
	int		cnt;

	s_path.x = main->p_x;
	s_path.y = main->p_y;
	cnt = 0;
	flood_fill(main->tmp, *main, s_path, &cnt);
	if (cnt != (main->exit_count + main->collectibles_count))
		return (1);
	return (0);
}
