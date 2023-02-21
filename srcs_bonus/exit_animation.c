/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 03:05:38 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/21 03:43:45 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static	void	put_exit1(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->animation.exit1,
		IMG_SIZE * game->map.exit_x, IMG_SIZE * game->map.exit_y);
}

static	void	put_exit2(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->animation.exit2, IMG_SIZE * game->map.exit_x,
		IMG_SIZE * game->map.exit_y);
}

static	void	put_exit3(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->animation.exit3,
		IMG_SIZE * game->map.exit_x, IMG_SIZE * game->map.exit_y);
}

static	void	put_exit4(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->animation.exit4,
		IMG_SIZE * game->map.exit_x, IMG_SIZE * game->map.exit_y);
}

void	exit_animation(t_game *game)
{
	static int	exit = 0;

	if (exit == 0)
	{
		put_exit1(game);
		exit = 1;
	}
	else if (exit == 1)
	{
		put_exit2(game);
		exit = 2;
	}
	else if (exit == 2)
	{
		put_exit3(game);
		exit = 3;
	}
	else if (exit == 3)
	{
		put_exit4(game);
		exit = 0;
	}
}
