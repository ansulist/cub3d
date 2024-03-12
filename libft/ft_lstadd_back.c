/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:06:59 by juhaamid          #+#    #+#             */
/*   Updated: 2022/10/25 13:46:09 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst && *lst)
	{
		temp = *lst;
		while (temp -> next)
			temp = temp ->next;
		temp -> next = new;
	}
	else
		*lst = new;
}
