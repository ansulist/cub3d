/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:52:53 by juhaamid          #+#    #+#             */
/*   Updated: 2022/10/31 15:28:40 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*latest;

	latest = (t_list *)malloc(sizeof(t_list));
	if (latest == NULL)
		return (NULL);
	latest ->content = content;
	latest->next = NULL;
	return (latest);
}
// allocates new(latest) node and return it
// latest node accesses value in content
