/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:45:48 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/13 03:32:55 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	find_char(const char *str, char c)
{
	int		a;

	a = 0;
	while (str[a])
	{
		if (str[a] == c)
		{
			return (1);
		}
			a++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	inicio;
	size_t	final;
	size_t	rvresult;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	inicio = 0;
	final = ft_strlen(s1);
	rvresult = final -1;
	while ((find_char(set, s1[inicio]) > 0) && s1[inicio])
		inicio++;
	while ((find_char(set, s1[rvresult]) > 0) && (final) > inicio)
	{
		rvresult--;
		final--;
	}
	trimmed = ft_substr(s1, inicio, final - inicio);
	return (trimmed);
}
