/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:10:56 by acanelas          #+#    #+#             */
/*   Updated: 2022/12/18 03:31:21 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int		a;

	a = 0;
	if (n <= 0)
	{
		n = n * (-1);
		++a;
	}
	while (n)
	{
		a++;
		n = n / 10;
	}
	return (a);
}

int	ft_putnumb(int n)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = int_len(n);
	str = ft_itoa(n);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (len);
}
