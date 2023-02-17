/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:02:29 by acanelas          #+#    #+#             */
/*   Updated: 2022/11/13 20:58:39 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *cont)
{
	t_list	*str;

	str = (t_list *)malloc(sizeof(t_list));
	if (!str)
		return (NULL);
	str->content = cont;
	str->next = NULL;
	return (str);
}
/*
int		main(void)
{
	char *str = "el papi";
	str = ft_strdup(str);
	char *str1 = "el paizao";
	str1 = ft_strdup(str1);
	t_list	*node1;
	node1 = ft_lstnew(str);
	t_list	*node2;
	node2 = ft_lstnew(str1);
	node1->next = node2;
	printf("%s\n", (char*)node2->content);
	printf("%p\n", (char*)node1->next);
	printf("%s\n", (char*)node1->content);
}
*/