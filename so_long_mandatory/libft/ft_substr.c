/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:50:56 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/13 03:49:29 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	a;

	a = 0;
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[a] = 0;
		return (str);
	}
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (s[start] && len > a)
	{
		str[a++] = s[start++];
	}
	str[a] = '\0';
	//free(str);
	return (str);
}
/*
int     main(void)
{
    char    *str = "claraboia";
    printf("%s", ft_substr(str, 5,sizeof(str) + 1));
}
*/