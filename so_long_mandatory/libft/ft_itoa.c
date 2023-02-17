/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:59:39 by acanelas          #+#    #+#             */
/*   Updated: 2023/01/12 01:49:10 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	neg_num(char *str, int n, int len)
{
	if (n < 0)
	{
		str[0] = '-';
		if (n == (-2147483648))
		{
		len--;
			while (len > 0)
			{
			str[len] = (n % 10 * (-1)) + 48;
			n = n / 10;
			len--;
			}
			return (0);
		}
		else
		n = n * (-1);
	}
	return (n);
}

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

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = int_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		if (neg_num(str, n, len) == 0)
			return (str);
		else
			n = neg_num(str, n, len);
	}
	else if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--len] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
/*
int		main(void)
{
	char *str;
	str = ft_itoa(54);
	printf("%s", str);
}
*/