/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 05:28:05 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/13 05:35:06 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t		a;
	size_t		b;
	char		*str;
	size_t		s1len;
	size_t		s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = ft_calloc((s1len + s2len + 1), sizeof(char));
	if (!str)
		return (NULL);
	a = 0;
	while (a < s1len)
	{
		str[a] = s1[a];
		a++;
	}
	b = 0;
	while (b < s2len)
		str[a++] = s2[b++];
	str[a] = '\0';
	free(s1);
	return (str);
}
