/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:58:10 by acanelas          #+#    #+#             */
/*   Updated: 2022/11/13 20:58:22 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	int			a;

	a = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		a++;
		lst = lst->next;
	}
	return (a);
}
/*
int		main(void)
{
	char *str = "el papi";
	str = ft_strdup(str);
	char *str1 = "el paizao";
	str1 = ft_strdup(str1);
	char *str2 = "el rei";
	str2 = ft_strdup(str2);
	t_list	*node1;
	node1 = ft_lstnew(str);
	t_list	*node2;
	node2 = ft_lstnew(str1);
	t_list	*node3;
	node3 = ft_lstnew(str2);
	node1->next = node2;
	node2->next = node3;
	printf("%d", ft_lstsize(node1));
}
*/