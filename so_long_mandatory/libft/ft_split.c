/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:07:00 by acanelas          #+#    #+#             */
/*   Updated: 2022/11/10 20:24:16 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	word_index(const char *s, char c)
{
	int		count;
	int		word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && count == 0)
		{
			count = 1;
			word++;
		}
		else if (*s == c)
			count = 0;
	s++;
	}
	return (word);
}

static int	letter_index(const char *s, char c, int a)
{
	int		len;

	len = 0;
	while (s[a] != c && s[a])
	{
		a++;
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t			word;
	size_t			a;
	size_t			b;
	char			**str;

	word = word_index(s, c);
	a = 0;
	b = 0;
	str = (char **)malloc(sizeof(char *) * (word + 1));
	if (!str)
		return (NULL);
	while (b < word)
	{
		while (s[a] == c)
		a++;
		str[b] = ft_substr(s, a, (letter_index(s, c, a)));
		if (!str)
			return (NULL);
	a += letter_index(s, c, a);
		b++;
	}
	str [b] = 0;
	return (str);
}
/*
int		main(void)
{
	char	str[] = "andre canelas kaldeich el papi";
	char **splited;
	int		a;
	a = 0;
	splited = ft_split(str, ' ');
	while (splited[a])
	{
		printf ("%s\n", splited[a]);
		a++;
	}
}
*/