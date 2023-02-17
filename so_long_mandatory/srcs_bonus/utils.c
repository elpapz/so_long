/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 00:12:01 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/16 09:41:59 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_array(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	//if (i != 0)
		free(str);
	//str = NULL;
}

void	ft_trouble(t_game *game, char *str)
{
	if (!game)
		return ;
	if (game->map.map)
		free_array(game->map.map);
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	ft_putstr_fd(str, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

int	char_search(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	entities_number(t_game *game)
{
	printf("CARALHO\n");
	if (game->map.coins == 0)
		return (0);
	if (game->map.exit != 1)
		return (0);
	if (game->map.player != 1)
		return (0);
	return (1);
}
