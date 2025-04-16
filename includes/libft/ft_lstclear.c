/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:32:15 by miovu             #+#    #+#             */
/*   Updated: 2024/11/18 15:45:38 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

/* #include <stdio.h>
void delete(void *content)
{
    free(content);
}

int	main()
{
	t_list	*head = ft_lstnew("Hello ");
	t_list	*head1 = ft_lstnew("world!");
	t_list	*head2 = ft_lstnew(" - from 42.");

	head->next = head1;
	head1->next = head2;
	
	while (head)
	{
		printf("List before clear: %s\n", (char *)head->content);
		head = head->next;
	}
	
	ft_lstclear(&head, delete);

	while (head)
	{
		printf("List after clear: %s\n", (char *)head->content);
		head = head->next;
	}
} */