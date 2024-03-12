/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:04:35 by juhaamid          #+#    #+#             */
/*   Updated: 2022/10/31 13:10:40 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstnew;
	t_list	*node;

	if (!f || !del)
		return (NULL);
	lstnew = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
		{
			ft_lstclear(&lstnew, del);
			return (NULL);
		}
		ft_lstadd_back(&lstnew, node);
		lst = lst->next;
	}
	return (lstnew);
}
// iterates list and applies f function to each node
// new lst contains content with f function applied
