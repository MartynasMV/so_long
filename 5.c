/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoldema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:57:04 by mvoldema          #+#    #+#             */
/*   Updated: 2023/03/10 14:57:06 by mvoldema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_assignment(t_map *main)
{
	int	height;
	int	width;

	main->wall = mlx_xpm_file_to_image(main->mlx_ptr, "./textures/w2.xpm",
			&width, &height);
	main->exit = mlx_xpm_file_to_image(main->mlx_ptr, "./textures/exit.xpm",
			&width, &height);
	main->player = mlx_xpm_file_to_image(main->mlx_ptr, "./textures/w.xpm",
			&width, &height);
	main->ground = mlx_xpm_file_to_image(main->mlx_ptr, "./textures/red.xpm",
			&width, &height);
	main->collectible = mlx_xpm_file_to_image(main->mlx_ptr,
			"./textures/h5.xpm", &width, &height);
}

void	parse_images(t_map *main, int x, int y)
{
	if (main->map[y][x] == '1')
		mlx_put_image_to_window(main->mlx_ptr, main->win_ptr, main->wall, SIZE
			* x, SIZE * y);
	else if (main->map[y][x] == 'E')
		mlx_put_image_to_window(main->mlx_ptr, main->win_ptr, main->exit, SIZE
			* x, SIZE * y);
	else if (main->map[y][x] == 'P')
		mlx_put_image_to_window(main->mlx_ptr, main->win_ptr, main->player, SIZE
			* x, SIZE * y);
	else if (main->map[y][x] == '0')
		mlx_put_image_to_window(main->mlx_ptr, main->win_ptr, main->ground, SIZE
			* x, SIZE * y);
	else if (main->map[y][x] == 'C')
		mlx_put_image_to_window(main->mlx_ptr, main->win_ptr, main->collectible,
			SIZE * x, SIZE * y);
}

int	render(t_map *main)
{
	int	x;
	int	y;

	y = 0;
	while (y < main->ycolumns)
	{
		x = 0;
		while (x < main->xlines)
		{
			parse_images(main, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
