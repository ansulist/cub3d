/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 09:05:19 by juhaamid          #+#    #+#             */
/*   Updated: 2022/10/17 12:31:17 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			j;

	ptr = (unsigned char *)b;
	j = 0;
	while (j < len)
	{
		ptr[j] = (unsigned char) c;
		j++;
	}
	return (ptr);
}
// fill block of memory with a certain value
