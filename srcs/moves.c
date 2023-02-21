/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 01:19:19 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/17 05:16:08 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_game *game)
{
	if (game->map.map[game->map.player_y - 1][game->map.player_x] != WALL)
	{
		if (game->map.map[game->map.player_y][game->map.player_x] == COIN)
		{
			game->map.map[game->map.player_y][game->map.player_x] = SPACE;
			game->map.coins -= 1;
			print_floor(game);
		}
		else if (game->map.map[game->map.player_y][game->map.player_x] == EXIT)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->animation.exit, IMG_SIZE * game->map.player_x,
				IMG_SIZE * game->map.player_y);
		}
		else
			print_floor(game);
		game->map.player_y -= 1;
		game->moves += 1;
		put_player(game);
	}
}

void	move_down(t_game *game)
{
	if (game->map.map[game->map.player_y + 1][game->map.player_x] != WALL)
	{
		if (game->map.map[game->map.player_y][game->map.player_x] == COIN)
		{
			game->map.map[game->map.player_y][game->map.player_x] = SPACE;
			game->map.coins -= 1;
			print_floor(game);
		}
		else if (game->map.map[game->map.player_y][game->map.player_x] == EXIT)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->animation.exit, IMG_SIZE * game->map.player_x,
				IMG_SIZE * game->map.player_y);
		}
		else
			print_floor(game);
		game->map.player_y += 1;
		game->moves += 1;
		put_player(game);
	}
}

void	move_left(t_game *game)
{
	if (game->map.map[game->map.player_y][game->map.player_x - 1] != WALL)
	{
		if (game->map.map[game->map.player_y][game->map.player_x] == COIN)
		{
			game->map.map[game->map.player_y][game->map.player_x] = SPACE;
			game->map.coins -= 1;
			print_floor(game);
		}
		else if (game->map.map[game->map.player_y][game->map.player_x] == EXIT)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->animation.exit, IMG_SIZE * game->map.player_x,
				IMG_SIZE * game->map.player_y);
		}
		else
			print_floor(game);
		game->map.player_x -= 1;
		game->moves += 1;
		put_player(game);
	}
}

void	move_right(t_game *game)
{
	if (game->map.map[game->map.player_y][game->map.player_x + 1] != WALL)
	{
		if (game->map.map[game->map.player_y][game->map.player_x] == COIN)
		{
			game->map.map[game->map.player_y][game->map.player_x] = SPACE;
			game->map.coins -= 1;
			print_floor(game);
		}
		else if (game->map.map[game->map.player_y][game->map.player_x] == EXIT)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->animation.exit, IMG_SIZE * game->map.player_x,
				IMG_SIZE * game->map.player_y);
		}
		else
			print_floor(game);
		game->map.player_x += 1;
		game->moves += 1;
		put_player(game);
	}
}

void	check_status(t_game *game)
{
	if (game->map.map[game->map.player_y][game->map.player_x]
		==EXIT && game->map.coins == 0)
	{
		ft_printf("CONGRATS!! YOU WON THIS GAME!! :)\n");
		ft_quit(game);
	}
}
