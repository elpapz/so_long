/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirm_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 05:43:40 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/17 00:22:55 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	check_perimeter(t_game *game)
{
	int	i;

	i = 0;
	printf("num col: %i\n num rows: %i\n", game->map.columns, game->map.rows);
	while (game->map.rows > i)
	{
		printf("map: %s\n", game->map.map[i]);
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
		ft_printf("map :%s\n", game->map.map[y]);
		x = -1;
		while (game->map.columns > ++x)
		{
			if (char_search(ENTITIES, game->map.map[y][x]) == 0)
				ft_trouble(game, "ENTITIES wrong at char_search");
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
		ft_trouble(game, "malloc error at **str");
	while (game->map.rows > i)
	{
		str->str[i] = ft_strdup(game->map.map[i]);
		if (!str->str[i])
		{
			free_array(str->str);
			ft_trouble(game, "malloc error while strduping");
		}
	i++;
	}
	/*if (!str->str[i])
	{
		free_array(str->str);
		ft_trouble(game, "fuck you hoe bitch\n");
	}*/

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


void	confirm_map(t_game *game)
{
	/*char	**str; SE PUSER O **STR ELE DÁ ME UNISIALIZED VALUE, 
	SE TROCAR PELO GAME->MAP.STR[i] ELE DÁ UN BUG QUALQUER!, SE CRIAR O GAME->DUPMAP.STR ELE DÁ O MESMO ERRO DO **STR!*/
	
	if (check_perimeter(game) == 0)
		ft_trouble(game, "Perimeter is wrong");
	check_entities(game);
	printf("num col: %i\n num rows: %i\n", game->map.columns, game->map.rows);
	ft_printf("coins : %d\n exit: %d\n player: %d\n", game->map.coins, game->map.exit, game->map.player);
	if (entities_number(game) == 0)
		ft_trouble(game, "Wrong quantity of entities");
	//check_path(game);
	array_dup(game, &game->dupmap);
	if (flood_fill(&game->map, game->map.player_x,
			game->map.player_y, game->dupmap.str) == 0)
	{
		free_array(game->dupmap.str);
		ft_trouble(game, "error on flood fill");
	}
	free_array(game->dupmap.str);
}
