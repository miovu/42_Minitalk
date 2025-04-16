/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:05:28 by miovu             #+#    #+#             */
/*   Updated: 2024/11/16 19:47:56 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
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

	int	i;
	
	i = ft_lstsize(head);
	printf("List size: %d", i);
	return (0);
} */