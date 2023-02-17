/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 04:51:31 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/16 04:54:39 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_player1(t_game *game)
{	
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,game->animation.player1,
			IMG_SIZE * game->map.player_x, IMG_SIZE * game->map.player_y);
}

void	put_player2(t_game *game)
{	
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,game->animation.player2,
			IMG_SIZE * game->map.player_x, IMG_SIZE * game->map.player_y);
}

void	print_floor(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,game->animation.floor,
			IMG_SIZE * game->map.player_x, IMG_SIZE * game->map.player_y);
}

void	print_moves(t_game *game)
{
	char	*moves;


	moves = ft_itoa(game->moves);
	ft_putstr_fd("Number of moves:", STDOUT_FILENO);
	ft_putendl_fd(moves, STDOUT_FILENO);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->animation.wall, 0, 0);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 15, 10, 0x00FF0000, moves);
	free(moves);
}