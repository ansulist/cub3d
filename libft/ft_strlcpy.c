/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:44:56 by juhaamid          #+#    #+#             */
/*   Updated: 2022/10/31 08:13:28 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;

	a = ft_strlen(src);
	b = 0;
	if (dstsize != 0)
	{
		while (src[b] != '\0' && b < dstsize - 1)
		{
			dst[b] = src[b];
			b++;
		}
		dst[b] = '\0';
	}
	return (a);
}
// copies src into dst.. size is len of buffer
// upto size - 1 is copied 
// returns the length of chars copied 
// if successful ret value value is less than size