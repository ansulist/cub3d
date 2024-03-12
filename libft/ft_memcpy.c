/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:54:50 by juhaamid          #+#    #+#             */
/*   Updated: 2022/10/28 09:28:23 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	bop;
	char	*ptr;
	char	*ptr1;

	bop = 0;
	ptr1 = (char *)src;
	ptr = (char *)dest;
	if ((!src && !dest))
		return (0);
	while (bop < n)
	{
		ptr[bop] = ptr1[bop];
		bop++;
	}
	return (dest);
}
// copy 1 mem block to another
// src mem block to dest
// n is the amount of characters