/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:41:42 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/17 00:19:58 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/*
static char	**array_dup(t_game *game)
{
	int		i;
	char **str;

	str = ft_calloc((game->map.rows + 1), sizeof(char *));
	if (!str)
		ft_trouble(game, "malloc error at **str");
	i = 0;
	while (game->map.rows > i)
	{
		str[i] = ft_strdup(game->map.map[i]);
		if (!str[i])
		{
			free_array(str);
			ft_trouble(game, "malloc error while strduping");
		}
	i++;
	}
	/*if (!str[i])
	{
		free_array(str);
		ft_trouble(game, "fuck you hoe bitch\n");
	
	return (str);
}


static int	flood_fill(t_map *map, int x, int y, char **str)
{
	static int	coins = 0;
	static int	exit = 0;

	if (str[y][x] == WALL)
		return (0);
	else if (str[y][x] == COIN)
		coins++;
	else if (str[y][x] == EXIT)
	{
		exit = 1;
		map->exit_y = y;
		map->exit_x = x;
	}
	str[y][x] = WALL;
	flood_fill(map, x + 1, y, str);
	flood_fill(map, x - 1, y, str);
	flood_fill(map, x, y + 1, str);
	flood_fill(map, x, y - 1, str);
	if (coins == map->coins && exit == 1)
		return (1);
	return (0);
}

void	check_path(t_game *game)
{
	char	**andre;

	andre = array_dup(game);
	if (flood_fill(&game->map, game->map.player_x, game->map.player_y, andre) == 0)
	{
		free_array(andre);
		ft_trouble(game, "FUCK YOUR FUCKING ASS");
	}
	free_array(andre);
}
*/