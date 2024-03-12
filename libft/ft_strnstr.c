/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:55:28 by juhaamid          #+#    #+#             */
/*   Updated: 2022/10/25 15:34:17 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	h;

	n = 0;
	h = 0;
	if (needle[n] == '\0')
		return ((char *)haystack);
	while (h < len && haystack[h] != '\0')
	{
		while (haystack[h + n] == needle[n]
			&& haystack[h + n] != '\0' && n + h < len)
			n++;
		if (needle[n] == '\0')
			return ((char *)haystack + h);
		h++;
		n = 0;
	}
	return (0);
}
// searches for needle in haystack string
// returns needle plus everything after or 0
