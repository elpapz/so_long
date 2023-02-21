/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:54:53 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/17 05:01:14 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_rows(char *filename, t_game *game)
{
	int		fd;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_trouble(game, "READ FAILED:(\n");
	temp = get_next_line(fd);
	if (!temp)
	{
		free(temp);
		ft_trouble(game, "File is BAD :(\n");
	}
	while (temp)
	{
		game->map.rows++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	return (game->map.rows);
}

static void	trim_lines(char *filename, t_game *game)
{
	int		fd;
	int		i;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_trouble(game, "READ FAILED :(\n");
	i = -1;
	while (game->map.rows > ++i)
	{
		temp = get_next_line(fd);
		game->map.map[i] = ft_strtrim(temp, "\n");
		free(temp);
		if (!game->map.map[i])
			ft_trouble(game, ERRORMALLOC);
	}
	game->map.map[i] = NULL;
	close(fd);
	game->map.columns = ft_strlen(game->map.map[0]);
}

static void	map_format(t_game *game)
{
	int		i;
	size_t	max;

	i = -1;
	max = ft_strlen(game->map.map[0]);
	while (game->map.map[++i])
	{
		if (max != ft_strlen(game->map.map[i]))
			ft_trouble(game, ERRORMAP);
	}
}

void	check_map(char *filename, t_game *game)
{
	int	rows;

	rows = check_rows(filename, game);
	game->map.map = malloc((rows + 1) * sizeof(char *));
	if (!game->map.map)
		ft_trouble(game, ERRORMALLOC);
	trim_lines(filename, game);
	map_format(game);
}
