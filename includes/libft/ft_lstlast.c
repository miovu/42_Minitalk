/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:09:33 by miovu             #+#    #+#             */
/*   Updated: 2024/11/16 19:31:47 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

/* #include <stdio.h>
int	main()
{
	t_list	*head = ft_lstnew("Hello");
	t_list	*temp = ft_lstnew("world");;
	t_list	*temp1 = ft_lstnew("everything");;
	t_list	*temp2 = ft_lstnew("okay");;
	
	head->next = temp;
	temp->next = temp1;
	temp1->next = temp2;

	printf("List last node: %s", (char *)ft_lstlast(head)->content);
	return (0);
} */