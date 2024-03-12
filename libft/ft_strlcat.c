/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:17:57 by juhaamid          #+#    #+#             */
/*   Updated: 2022/10/31 12:32:34 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;
	size_t	len;

	if (dst == NULL && src == NULL)
		return (0);
	a = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	len = ft_strlen(dst);
	if (dstsize > len)
	{
		b = ft_strlen(src) + len;
		while (src[a] != '\0' && len < dstsize - 1)
		{
			dst[len] = src[a];
			a++;
			len++;
		}
		dst[len] = '\0';
	}
	else
		b = dstsize + ft_strlen(src);
	return (b);
}
// concatenates dst & src with size of dstbuffer
// returns length of concatenated string
// appends the entire src to the dst
//more stable than strncpy