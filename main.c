/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoldema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:44:47 by mvoldema          #+#    #+#             */
/*   Updated: 2023/03/10 10:44:49 by mvoldema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int ac, char **av)
{
	int		i;
	t_map	main;

	i = 0;
	init(&main);
	check_input_part_1(ac, av, &main);
	check_input_part_2(av, &main);
	main.mlx_ptr = mlx_init();
	main.win_ptr = mlx_new_window(main.mlx_ptr, main.xlines * SIZE,
			main.ycolumns * SIZE, "so_long");
	img_assignment(&main);
	mlx_hook(main.win_ptr, KeyPress, KeyPressMask, &input_handling, &main);
	mlx_hook(main.win_ptr, 17, 0, &close_all, &main);
	mlx_loop_hook(main.mlx_ptr, &render, &main);
	mlx_loop(main.mlx_ptr);
}
