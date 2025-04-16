/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:27:43 by miovu             #+#    #+#             */
/*   Updated: 2024/11/18 15:47:42 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

/* #include <stdio.h>
void delete(void *content)
{
    free(content);
}

int	main()
{
	char	*content = ft_strdup("Hello World!");
	t_list	*head = ft_lstnew(content);

	printf("List before delone: %s\n", (char *)head->content);
	
	ft_lstdelone(head, delete);

	printf("List after delone: %s\n", (char *)head->content);
	return (0);
} */