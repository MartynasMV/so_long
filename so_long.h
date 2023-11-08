/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoldema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:48:34 by mvoldema          #+#    #+#             */
/*   Updated: 2023/03/10 10:48:35 by mvoldema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./minilibx-linuxv2/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdint.h>
# include <stdlib.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define MLX_ERROR 1
# define WHITE_PIXEL 0xFF0000
# define SIZE 96

typedef struct s_path
{
	int		x;
	int		y;
}			t_path;

typedef struct s_map
{
	void	*win_ptr;
	void	*mlx_ptr;

	void	*img_ptr;
	void	*mlx_new_image;
	void	*wall;
	void	*exit;
	void	*player;
	void	*ground;
	void	*collectible;

	char	**map;
	char	**tmp;
	int		ycolumns;
	int		xlines;
	int		valid;
	int		char_count;
	int		collectibles_count;
	int		player_count;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		ones_count;
	int		zero_count;
	int		exit_count;
	int		collected_counter;
	int		is_it_collectible;
	int		move_count;
}			t_map;
int			column_counter(t_map *main, char *file_name);
void		main_calloc_and_fill(t_map *main, char *file_name);
void		first_line_counter(t_map *main);
void		horisontal_line_validator(t_map *main);
void		wall_checker_top_bottom(t_map *main);
void		wall_checker_left_right(t_map *main);
void		check_for_collectibles(t_map *main, char c);
void		check_for_forbidden_characters(t_map *main);
void		check_player_xy_position(t_map *main);

void		check_exit_xy_position(t_map *main);
void		temp_main_calloc(t_map *main, char *file_name);
int			dfs(t_map *main, int y, int x);
int			dfs_searching_for_collectible(t_map *main, int y, int x);

void		check_input_part_1(int ac, char **av, t_map *main);
void		check_input_part_2(char **av, t_map *main);
void		init(t_map *main);
void		destroy_all_images(t_map *main);
int			close_all(t_map *main);

void		img_assignment(t_map *main);
void		parse_images(t_map *main, int x, int y);
int			render(t_map *main);

void		check_dot_ber(int ac, char **av);
int			input_handling(int keycode, t_map *main);
int			close_all(t_map *main);
int			render(t_map *main);
int			pathfinder(t_map *main);

#endif
