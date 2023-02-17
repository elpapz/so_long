/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:08:15 by acanelas          #+#    #+#             */
/*   Updated: 2022/12/18 03:28:47 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(unsigned int n)
{
	int		a;

	a = 0;
	while (n)
	{
		a++;
		n = n / 10;
	}
	return (a);
}

static char	*ft_itoa_unsigned(unsigned int n)
{
	char				*str;
	int					len;

	len = int_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (n > 0)
	{
		str[--len] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}

int	ft_putunsigned(unsigned int n)
{
	int		len;
	char	*numb;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		numb = ft_itoa_unsigned(n);
		len += ft_putstr_ret_len(numb);
		free(numb);
	}
	return (len);
}
