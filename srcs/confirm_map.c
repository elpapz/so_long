/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirm_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 05:43:40 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/17 06:03:51 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_perimeter(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.rows > i)
	{
		if (game->map.map[i][0] != WALL
			||game->map.map[i][game->map.columns - 1] != WALL)
			return (0);
		i++;
	}
	i = 0;
	while (game->map.columns > i)
	{
		if (game->map.map[0][i] != WALL
			||game->map.map[game->map.rows - 1][i] != WALL)
			return (0);
		i++;
	}
	return (1);
}

static void	check_entities(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map.rows > ++y)
	{
		x = -1;
		while (game->map.columns > ++x)
		{
			if (char_search(ENTITIES, game->map.map[y][x]) == 0)
				ft_trouble(game, ERRORENTITIES);
			if (game->map.map[y][x] == COIN)
				game->map.coins++;
			else if (game->map.map[y][x] == EXIT)
				game->map.exit++;
			else if (game->map.map[y][x] == PLAYER)
			{
				game->map.player++;
				game->map.player_x = x;
				game->map.player_y = y;
			}
		}
	}
}

static void	array_dup(t_game *game, t_dupmap *str)
{
	int		i;

	i = 0;
	str->str = malloc((game->map.rows + 1) * sizeof(char *));
	if (!str->str)
		ft_trouble(game, ERRORMALLOC);
	while (game->map.rows > i)
	{
		str->str[i] = ft_strdup(game->map.map[i]);
		if (!str->str[i])
		{
			free_array(str->str);
			ft_trouble(game, ERRORMALLOC);
		}
	i++;
	}
	str->str[i] = NULL;
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

void	confirm_map(t_game *game)
{	
	if (check_perimeter(game) == 0)
		ft_trouble(game, ERRORMAP);
	check_entities(game);
	if (entities_number(game) == 0)
		ft_trouble(game, ERRORENTITIES);
	array_dup(game, &game->dupmap);
	if (flood_fill(&game->map, game->map.player_x,
			game->map.player_y, game->dupmap.str) == 0)
	{
		free_array(game->dupmap.str);
		ft_trouble(game, ERRORMAP);
	}
	free_array(game->dupmap.str);
}
