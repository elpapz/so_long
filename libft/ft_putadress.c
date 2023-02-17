/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 03:36:14 by acanelas          #+#    #+#             */
/*   Updated: 2022/12/18 03:27:40 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	count_hex(unsigned long long n)
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

static void	ft_pointer(unsigned long long n)
{
	if (n >= 16)
	{
		ft_pointer(n / 16);
		ft_pointer(n % 16);
	}
	else if (n <= 9)
		ft_putchar(n + '0');
	else
		ft_putchar(n + 87);
}

int	ft_putadress(unsigned long long n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		i = write(1, "0x", 2);
		ft_pointer(n);
	}
	return (i + count_hex(n));
}
/*
int	main(void)
{
	unsigned int a = 894;
	printf("%p\n", 0);
	//ft_putadress(a);
	ft_printf("%p\n", 0);
	
}
*/