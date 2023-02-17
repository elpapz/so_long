/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:17:22 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/16 02:35:13 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_xpm(t_game *game)
{
	if (!game->animation.collectible)
		ft_error(game, "trouble at converting collectible img");
	if (!game->animation.exit1)
		ft_error(game, "trouble at converting finish img");
	if (!game->animation.exit2)
		ft_error(game, "trouble at converting finish img");
	if (!game->animation.exit3)
		ft_error(game, "trouble at converting finish img");
	if (!game->animation.exit4)
		ft_error(game, "trouble at converting finish img");
	if (!game->animation.player1)
		ft_error(game, "trouble at converting player img");
	if (!game->animation.player2)
		ft_error(game, "trouble at converting player img");
	if (!game->animation.wall)
		ft_error(game, "trouble at converting wall img");
	if (!game->animation.floor)
		ft_error(game, "trouble at converting floor img");
}

static void	xmp_to_image(t_game *game)
{
	int	img_size;

	img_size = IMG_SIZE;
	game->animation.exit1 = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_IMG1,
			&img_size, &img_size);
	game->animation.exit2 = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_IMG2,
			&img_size, &img_size);
	game->animation.exit3 = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_IMG3,
			&img_size, &img_size);
	game->animation.exit4 = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_IMG4,
			&img_size, &img_size);
	game->animation.player1 = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_IMG1,
			&img_size, &img_size);
	game->animation.player2 = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_IMG2,
			&img_size, &img_size);
	game->animation.wall = mlx_xpm_file_to_image(game->mlx_ptr, WALL_IMG,
			&img_size, &img_size);
	game->animation.floor = mlx_xpm_file_to_image(game->mlx_ptr, FLOOR_IMG,
			&img_size, &img_size);
	game->animation.collectible = mlx_xpm_file_to_image(game->mlx_ptr, COIN_IMG,
			&img_size, &img_size);
	check_xpm(game);
}

void	creat_map_image(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.rows > y)
	{
		x = 0;
		while (game->map.columns > x)
		{
			if (game->map.map[y][x] == WALL)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->animation.wall, IMG_SIZE * x, IMG_SIZE * y);
			else if (game->map.map[y][x] == COIN)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->animation.collectible, IMG_SIZE * x, IMG_SIZE * y);
			else if (game->map.map[y][x] == EXIT)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->animation.exit1, IMG_SIZE * x, IMG_SIZE * y);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->animation.floor, IMG_SIZE * x, IMG_SIZE * y);
			x++;
		}
		y++;
	}
	put_player1(game);
}

void	init_graphic(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		ft_error(game, "trouble at mlx_init");
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.columns * IMG_SIZE,
			game->map.rows * IMG_SIZE, "so_long");
	if (!game->win_ptr)
		ft_error(game, "trouble at new_window");
	xmp_to_image(game);
	creat_map_image(game);
}
