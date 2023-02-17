/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_graphic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:41:40 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/16 05:50:38 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	kill_animations(t_game *game)
{
	if (game->animation.collectible)
		mlx_destroy_image(game->mlx_ptr, game->animation.collectible);
	if (game->animation.player1)
		mlx_destroy_image(game->mlx_ptr, game->animation.player1);
	if (game->animation.player1)
		mlx_destroy_image(game->mlx_ptr, game->animation.player2);
	if (game->animation.floor)
		mlx_destroy_image(game->mlx_ptr, game->animation.floor);
	if (game->animation.wall)
		mlx_destroy_image(game->mlx_ptr, game->animation.wall);
	if (game->animation.exit1)
		mlx_destroy_image(game->mlx_ptr, game->animation.exit1);
	if (game->animation.exit2)
		mlx_destroy_image(game->mlx_ptr, game->animation.exit2);
	if (game->animation.exit3)
		mlx_destroy_image(game->mlx_ptr, game->animation.exit3);
	if (game->animation.exit4)
		mlx_destroy_image(game->mlx_ptr, game->animation.exit4);
}

void	ft_error(t_game *game, char *str)
{
	delete_graphic(game);
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	ft_putstr_fd(str, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

int	ft_quit(t_game *game)
{
	delete_graphic(game);
	exit (EXIT_SUCCESS);
}

void	delete_graphic(t_game *game)
{
	if (!game)
		return ;
	if (game->map.map)
		free_array(game->map.map);
	kill_animations(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
}
