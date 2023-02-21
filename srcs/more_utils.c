/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 04:51:31 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/17 04:34:45 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_player(t_game *game)
{	
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->animation.player, IMG_SIZE * game->map.player_x,
		IMG_SIZE * game->map.player_y);
}

void	print_floor(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->animation.floor, IMG_SIZE * game->map.player_x,
		IMG_SIZE * game->map.player_y);
}

void	print_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->moves);
	ft_putstr_fd("Number of moves:", STDOUT_FILENO);
	ft_putendl_fd(moves, STDOUT_FILENO);
	free(moves);
}
