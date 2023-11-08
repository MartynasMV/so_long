/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoldema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:56:59 by mvoldema          #+#    #+#             */
/*   Updated: 2023/03/10 14:57:00 by mvoldema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_input_part_1(int ac, char **av, t_map *main)
{
	check_dot_ber(ac, av);
	column_counter(main, av[1]);
	main_calloc_and_fill(main, av[1]);
	first_line_counter(main);
	horisontal_line_validator(main);
	wall_checker_top_bottom(main);
	wall_checker_left_right(main);
	check_for_collectibles(main, 'C');
	check_for_forbidden_characters(main);
	check_player_xy_position(main);
	check_exit_xy_position(main);
}

void	check_input_part_2(char **av, t_map *main)
{
	temp_main_calloc(main, av[1]);
	if (dfs(main, main->p_y, main->p_x) != 1)
	{
		ft_printf("Error\nExit is unreachable\n");
		free_double_array(main->map);
		free_double_array(main->tmp);
		exit(1);
	}
	free_double_array(main->tmp);
	temp_main_calloc(main, av[1]);
	if (pathfinder(main) != 0)
	{
		ft_printf("Error\nCollectible is unreachable\n");
		free_double_array(main->map);
		free_double_array(main->tmp);
		exit(1);
	}
	free_double_array(main->tmp);
}

void	init(t_map *main)
{
	main->map = NULL;
	main->tmp = NULL;
	main->ycolumns = 0;
	main->xlines = 0;
	main->valid = 0;
	main->char_count = 0;
	main->collectibles_count = 0;
	main->player_count = 0;
	main->p_x = 0;
	main->p_y = 0;
	main->ones_count = 0;
	main->zero_count = 0;
	main->exit_count = 0;
	main->collected_counter = 0;
	main->is_it_collectible = 0;
	main->move_count = 0;
	main->wall = NULL;
	main->exit = NULL;
	main->player = NULL;
	main->ground = NULL;
	main->collectible = NULL;
}

void	destroy_all_images(t_map *main)
{
	mlx_destroy_image(main->mlx_ptr, main->wall);
	mlx_destroy_image(main->mlx_ptr, main->exit);
	mlx_destroy_image(main->mlx_ptr, main->player);
	mlx_destroy_image(main->mlx_ptr, main->ground);
	mlx_destroy_image(main->mlx_ptr, main->collectible);
}

int	close_all(t_map *main)
{
	mlx_destroy_window(main->mlx_ptr, main->win_ptr);
	main->win_ptr = NULL;
	destroy_all_images(main);
	mlx_destroy_display(main->mlx_ptr);
	free(main->win_ptr);
	free(main->mlx_ptr);
	free_double_array(main->map);
	exit(1);
}
