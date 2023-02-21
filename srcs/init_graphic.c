/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:17:22 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/17 05:07:44 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_xpm(t_game *game)
{
	if (!game->animation.collectible)
		ft_error(game, ERRORXPM);
	if (!game->animation.exit)
		ft_error(game, ERRORXPM);
	if (!game->animation.player)
		ft_error(game, ERRORXPM);
	if (!game->animation.wall)
		ft_error(game, ERRORXPM);
	if (!game->animation.floor)
		ft_error(game, ERRORXPM);
}

static void	xmp_to_image(t_game *game)
{
	int	img_size;

	img_size = IMG_SIZE;
	game->animation.exit = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_IMG,
			&img_size, &img_size);
	game->animation.player = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_IMG,
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

	y = -1;
	while (game->map.rows > ++y)
	{
		x = -1;
		while (game->map.columns > ++x)
		{
			if (game->map.map[y][x] == WALL)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->animation.wall, IMG_SIZE * x, IMG_SIZE * y);
			else if (game->map.map[y][x] == COIN)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->animation.collectible, IMG_SIZE * x, IMG_SIZE * y);
			else if (game->map.map[y][x] == EXIT)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->animation.exit, IMG_SIZE * x, IMG_SIZE * y);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->animation.floor, IMG_SIZE * x, IMG_SIZE * y);
		}
	}
	put_player(game);
}

void	init_graphic(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		ft_error(game, "MLX_INIT is not working :(\n");
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.columns * IMG_SIZE,
			game->map.rows * IMG_SIZE, "so_long");
	if (!game->win_ptr)
		ft_error(game, "FAILED TO OPEN WINDOW :(\n");
	xmp_to_image(game);
	creat_map_image(game);
}
