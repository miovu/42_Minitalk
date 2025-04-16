/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:45:30 by miovu             #+#    #+#             */
/*   Updated: 2024/11/18 15:19:39 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;
	void	*content;

	new = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		if (!content)
			ft_lstclear(&new, del);
		temp = ft_lstnew(content);
		if (!temp)
		{
			del(content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}

/* #include <stdio.h>
void	*uppercase(void	*content)
{
	char	*str;
	char	*new_str;
	int		len;
	int		i;

	str = (char *)content;
	len = ft_strlen(str);
	new_str = malloc((sizeof (char *)) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = ft_toupper(str[i]);
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}

void	printlist(void *content)
{
	if (content)
		printf("%s", (char *)content);
}

void delete(void *content)
{
    free(content);
}

int	main()
{
	t_list	*head = ft_lstnew(ft_strdup("Hello "));
	t_list	*head1 = ft_lstnew(ft_strdup("world!"));
	t_list	*head2 = ft_lstnew(ft_strdup(" - from 42.\n"));

	head->next = head1;
	head1->next = head2;

	t_list	*new_head;

	new_head = ft_lstmap(head, uppercase, delete);

	printf("Original list: \n");
	ft_lstiter(head, printlist);
	
	printf("New list: \n");
	ft_lstiter(new_head, printlist);

	ft_lstclear(&head, delete);
	ft_lstclear(&new_head, delete);
} */