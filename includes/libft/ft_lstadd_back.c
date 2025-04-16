/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:32:15 by miovu             #+#    #+#             */
/*   Updated: 2025/01/27 17:06:00 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}

/* #include <stdio.h>
int main(void)
{
	t_list	*head;

	head = ft_lstnew("Hello,");
	ft_lstadd_back(&head, ft_lstnew("world"));
	
	t_list	*temp1 = head;
	while(temp1)
	{
		printf("List: %s\n", (char *)temp1->content);
		temp1 = temp1->next;
	}
} */