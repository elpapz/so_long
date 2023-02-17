/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:28:29 by acanelas          #+#    #+#             */
/*   Updated: 2022/12/18 03:28:06 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	count_hex(unsigned long n)
{
	unsigned int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

static void	ft_convert(unsigned int n, const char type)
{
	int	alpha;

	alpha = 0;
	if (type == 'X')
		alpha = 55;
	else
		alpha = 87;
	if (n >= 16)
	{
		ft_convert(n / 16, type);
		ft_convert(n % 16, type);
	}
	else if (n <= 9)
		ft_putchar(n + '0');
	else
		ft_putchar(n + alpha);
}

int	ft_puthex(unsigned int n, const char type)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_convert(n, type);
	return (count_hex(n));
}
/*
int	main(void)
{
	unsigned int a = 894;
	char c = 'X';
	printf("%X\n", a);
	ft_puthex(a, c);
	printf("%d\n", a);
}
*/