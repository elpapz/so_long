/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 05:49:45 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/21 03:58:26 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_arg(int ac, char **av)
{
	int	i;

	i = ft_strlen(av[1]);
	if (ac != 2)
	{
		ft_printf("Error:\nWrong number of arguments");
		exit (EXIT_SUCCESS);
	}
	if (!ft_strnstr(av[1], ".ber", i))
	{
		ft_printf("Error:\nWrong argument! Try to write '.ber' at the end");
		exit (EXIT_SUCCESS);
	}
}

static t_game	start_struct(void)
{
	t_game	game;

	game.map.map = NULL;
	game.map.rows = 0;
	game.map.columns = 0;
	game.map.exit = 0;
	game.map.player = 0;
	game.map.coins = 0;
	game.map.player_x = 0;
	game.map.player_y = 0;
	game.moves = 0;
	game.animation.collectible = NULL;
	game.animation.floor = NULL;
	game.animation.wall = NULL;
	game.animation.player = NULL;
	game.animation.exit = NULL;
	return (game);
}

int	press_key(int key, t_game *game)
{
	if (key == ESC)
	{
		ft_quit(game);
	}
	else if (key == W || key == UP)
		move_up(game);
	else if (key == A || key == LEFT)
		move_left(game);
	else if (key == S || key == DOWN)
		move_down(game);
	else if (key == D || key == RIGHT)
		move_right(game);
	check_status(game);
	print_moves(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_arg(argc, argv);
	game = start_struct();
	check_map(argv[1], &game);
	confirm_map(&game);
	init_graphic(&game);
	mlx_hook(game.win_ptr, 2, 1L << 0, press_key, &game);
	mlx_hook(game.win_ptr, 17, 1L << 17, ft_quit, &game);
	mlx_loop(game.mlx_ptr);
}
