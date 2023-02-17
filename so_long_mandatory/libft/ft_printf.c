/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:42:16 by acanelas          #+#    #+#             */
/*   Updated: 2022/12/18 05:32:00 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_conversions(va_list param, char str)
{
	int	len;

	len = 0;
	if (str == 'c')
		len += ft_putchar_ret_len(va_arg(param, int));
	else if (str == '%')
		len += ft_putchar_ret_len('%');
	else if (str == 's')
		len += ft_putstr_ret_len(va_arg(param, char *));
	else if (str == 'd' || str == 'i')
		len += ft_putnumb(va_arg(param, int));
	else if (str == 'u')
		len += ft_putunsigned(va_arg(param, unsigned int));
	else if (str == 'x' || str == 'X')
		len += ft_puthex(va_arg(param, unsigned int), str);
	else if (str == 'p')
		len += ft_putadress(va_arg(param, unsigned long long));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		total_len;

	i = 0;
	total_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			total_len += ft_conversions(args, str[i]);
		}
		else
			total_len += ft_putchar_ret_len(str[i]);
	i++;
	}
	va_end(args);
	return (total_len);
}
/*
int	main(void)
{
	int a = 42;
	ft_printf("%X\n", a);
	printf("%X", a);
}
*/