/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:23:29 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/15 21:59:12 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		a;
	char		*new;

	a = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	while (s[a])
	{
		new[a] = s[a];
		a++;
	}
	new[a] = '\0';
	return (new);
}
/*
int		main(void)
{
	char old [] = "hoes & cash";
	char *new;
	new = ft_strdup(old);
	printf("%s", new);
}
*/