/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:32:15 by miovu             #+#    #+#             */
/*   Updated: 2025/01/29 14:54:31 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/* #include <stdio.h>
int	main()
{
	t_list	*head;
	t_list	*new = NULL;
	
	head = ft_lstnew("World!");
	new = ft_lstnew("Hello,");
	ft_lstadd_front(&head, new);

	t_list	*temp = head;
	while (temp)
	{
		printf("List: %s\n", (char *)temp->content);
		temp = temp->next;
	}
	return (0);
} */