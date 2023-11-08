/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoldema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:20:30 by mvoldema          #+#    #+#             */
/*   Updated: 2023/03/10 14:20:32 by mvoldema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_map *main)
{
	if (main->map[main->p_y - 1][main->p_x] == 'C')
		main->collected_counter += 1;
	if (main->p_y - 1 == main->e_y && main->p_x == main->e_x
		&& main->collected_counter == main->collectibles_count)
	{
		close_all(main);
	}
	if (main->map[main->p_y - 1][main->p_x] != '1')
	{
		if (main->p_y == main->e_y && main->p_x == main->e_x)
			main->map[main->e_y][main->e_x] = 'E';
		else
			main->map[main->p_y][main->p_x] = '0';
		main->map[main->p_y - 1][main->p_x] = 'P';
		main->p_y -= 1;
		main->move_count += 1;
		ft_printf("\nMove counter: %i\n", main->move_count);
	}
	if (main->move_count == 2147483646)
		main->move_count = 0;
	return (0);
}

int	move_down(t_map *main)
{
	if (main->map[main->p_y + 1][main->p_x] == 'C')
		main->collected_counter += 1;
	if (main->p_y + 1 == main->e_y && main->p_x == main->e_x
		&& main->collected_counter == main->collectibles_count)
	{
		close_all(main);
	}
	if (main->map[main->p_y + 1][main->p_x] != '1')
	{
		if (main->p_y == main->e_y && main->p_x == main->e_x)
			main->map[main->e_y][main->e_x] = 'E';
		else
			main->map[main->p_y][main->p_x] = '0';
		main->map[main->p_y + 1][main->p_x] = 'P';
		main->p_y += 1;
		main->move_count += 1;
		ft_printf("\nMove counter: %i\n", main->move_count);
	}
	if (main->move_count == 2147483646)
		main->move_count = 0;
	return (0);
}

int	move_left(t_map *main)
{
	if (main->map[main->p_y][main->p_x - 1] == 'C')
		main->collected_counter += 1;
	if (main->p_y == main->e_y && main->p_x - 1 == main->e_x
		&& main->collected_counter == main->collectibles_count)
	{
		close_all(main);
	}
	if (main->map[main->p_y][main->p_x - 1] != '1')
	{
		if (main->p_y == main->e_y && main->p_x == main->e_x)
			main->map[main->e_y][main->e_x] = 'E';
		else
			main->map[main->p_y][main->p_x] = '0';
		main->map[main->p_y][main->p_x - 1] = 'P';
		main->p_x -= 1;
		main->move_count += 1;
		ft_printf("\nMove counter: %i\n", main->move_count);
	}
	if (main->move_count == 2147483646)
		main->move_count = 0;
	return (0);
}

int	move_right(t_map *main)
{
	if (main->map[main->p_y][main->p_x + 1] == 'C')
		main->collected_counter += 1;
	if (main->p_y == main->e_y && main->p_x + 1 == main->e_x
		&& main->collected_counter == main->collectibles_count)
	{
		close_all(main);
	}
	if (main->map[main->p_y][main->p_x + 1] != '1')
	{
		if (main->p_y == main->e_y && main->p_x == main->e_x)
			main->map[main->e_y][main->e_x] = 'E';
		else
			main->map[main->p_y][main->p_x] = '0';
		main->map[main->p_y][main->p_x + 1] = 'P';
		main->p_x += 1;
		main->move_count += 1;
		ft_printf("\nMove counter: %i\n", main->move_count);
	}
	if (main->move_count == 2147483646)
		main->move_count = 0;
	return (0);
}

int	input_handling(int keycode, t_map *main)
{
	if (keycode == XK_Escape)
		close_all(main);
	else if (keycode == XK_Up || keycode == XK_w)
		move_up(main);
	else if (keycode == XK_Down || keycode == XK_s)
		move_down(main);
	else if (keycode == XK_Left || keycode == XK_a)
		move_left(main);
	else if (keycode == XK_Right || keycode == XK_d)
		move_right(main);
	render(main);
	return (0);
}
