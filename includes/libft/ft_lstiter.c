/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:40:59 by miovu             #+#    #+#             */
/*   Updated: 2024/11/18 19:41:54 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* #include <stdio.h>
void	printlist(void *content)
{
	if (content)
		printf("%s", (char *)content);
}

int	main()
{
	t_list	*head = ft_lstnew("Hello ");
	t_list	*head1 = ft_lstnew("world!");
	t_list	*head2 = ft_lstnew(" - from 42.\n");

	head->next = head1;
	head1->next = head2;

	ft_lstiter(head, printlist);
	
	t_list	*temp;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
} */