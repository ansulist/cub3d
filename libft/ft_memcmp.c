/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:17:26 by juhaamid          #+#    #+#             */
/*   Updated: 2022/11/01 16:59:40 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;
	size_t			i;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (st1[i] != st2[i])
		{
			return (st1[i] - st2[i]);
		}
		i++;
	}
	return (0);
}
// compares n bytes in memory pointed by *s1 and *s2.. 
// return values (less than 0.. s1 less than s2, greater than 0..
//  s2 less than s1, equal to 0.. both s1 and s2 are equal)
// subtracting the ascii values