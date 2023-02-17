/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:54:52 by acanelas          #+#    #+#             */
/*   Updated: 2022/11/13 19:45:17 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
t_list *ft_lstlast(t_list *lst)
{
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
	
}
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
int		main(void)
{
	t_list *head;
	t_list *new;

	head = malloc(sizeof(t_list));
	new = malloc(sizeof(t_list));
	head->content = (char *)"andre";
	head->next = new;
	new->content = (char *)"canelas";
	new->next = NULL;
	
	while (head != NULL)
	{
		printf("%s\n", (char*)head->content);
		head = head->next;
	}
	
	t_list *add;
	add = malloc(sizeof(t_list));
	add->content = (char *)"kaldeich";
	add->next = head;
	head = add;
	
	while (head != NULL)
	{
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
	
	t_list *add2;
	add2 = malloc(sizeof(t_list));
	add2->content = (char *)"el papi";
	ft_lstadd_front(&head, add2);
	
	while (head != NULL)
	{
		printf("%s\n", (char *)head->content);
		head = head->next;
		
	}
	
	t_list *tmp;
	tmp =  ft_lstlast(head);
	printf("%s", (char *)tmp->content);	
}
*/