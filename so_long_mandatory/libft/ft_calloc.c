/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:46:40 by acanelas          #+#    #+#             */
/*   Updated: 2022/11/08 20:44:29 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	str = malloc(size * nmemb);
	if (!str)
		return (NULL);
	ft_memset(str, 0, nmemb);
	return (str);
}
/*
int		main(void)
{
	char	*str;
	if (!(str = ft_calloc(5, sizeof(char))))
	{
		printf("calloc is fucked");
	}
	printf("%i", *str);

}
*/