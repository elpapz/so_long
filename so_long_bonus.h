/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 04:03:54 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/16 20:49:41 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"

# define IMG_SIZE 32

# define MSG "FUCK YOU HOE!\n"

# define SPACE '0'
# define WALL '1'
# define EXIT 'E'
# define PLAYER 'P'
# define COIN 'C'

# define ENTITIES "01EPC"

# define S 115
# define D 100
# define W 119
# define A 97

# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361

# define ESC 65307

# define FLOOR_IMG "./img/floor.xpm"
# define WALL_IMG "./img/wall.xpm"
# define COIN_IMG "./img/coin.xpm"
# define PLAYER_IMG1 "./img/player.xpm"
# define PLAYER_IMG2 "./img/player2.xpm"
# define EXIT_IMG1 "./img/finish.xpm"
# define EXIT_IMG2 "./img/finish2.xpm"
# define EXIT_IMG3 "./img/finish3.xpm"
# define EXIT_IMG4 "./img/finish4.xpm"

typedef struct s_dupmap
{
	char	**str;
}			t_dupmap;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		columns;
	int		exit;
	int		coins;
	int		player;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
}			t_map;

typedef struct s_animation
{
	void	*wall;
	void	*floor;
	void	*player1;
	void	*player2;
	void	*collectible;
	void	*exit1;
	void	*exit2;
	void	*exit3;
	void	*exit4;
}			t_animation;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				moves;
	t_map			map;
	t_animation		animation;
	t_dupmap		dupmap;
}					t_game;

void	check_map(char *filename, t_game *game);
void	check_xpm(t_game *game);
void	check_path(t_game *game);

void	ft_error(t_game *game, char *str);
int		ft_quit(t_game *game);
void	ft_trouble(t_game *game, char *str);
int		char_search(const char *s, char c);
int		entities_number(t_game *game);
void	free_array(char **str);

void	confirm_map(t_game *game);

void	delete_graphic(t_game *game);

void	init_graphic(t_game *game);
void	run_map_image(t_game *game);
void	creat_map_image(t_game *game);
void	put_map(t_game *game);

void	move_up(t_game *game);
void	up_sprites(t_game *game);
void	move_down(t_game *game);
void	down_sprites(t_game *game);
void	move_left(t_game *game);
void	left_sprites(t_game *game);
void	move_right(t_game *game);
void	right_sprites(t_game *game);
void	check_status(t_game *game);
void	put_player1(t_game *game);
void	put_player2(t_game *game);
void	print_floor(t_game *game);
void	print_moves(t_game *game);

#endif