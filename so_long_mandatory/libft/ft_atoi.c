/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:35:41 by acanelas          #+#    #+#             */
/*   Updated: 2022/11/06 22:06:05 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int		s;
	int		r;
	int		a;

	a = 0;
	r = 0;
	s = 1;
	while ((str[a] >= 9 && str[a] <= 13) || (str[a] == 32))
	a++;
	if (str[a] == '-')
	{
		s = -1;
		a++;
	}
	else if (str[a] == '+')
	a++;
	while (str[a] && str[a] >= '0' && str[a] <= '9')
	{
		r = r * 10 + (str[a] - '0');
		a++;
	}
	return (r * s);
}
/*
int		main(void)
{
	char *str = "123f4567";
	printf("%i", ft_atoi(str));
}
*/