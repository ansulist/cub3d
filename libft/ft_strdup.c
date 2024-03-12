/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:36:50 by juhaamid          #+#    #+#             */
/*   Updated: 2022/10/24 12:16:18 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		bop;

	bop = 0;
	while (s1[bop])
		bop++;
	dest = malloc(sizeof(char) * bop + 1);
	bop = 0;
	if (dest == NULL)
		return (NULL);
	else
	{
		while (s1[bop])
		{
			dest[bop] = s1[bop];
			bop++;
		}
		dest[bop] = '\0';
		return (dest);
	}
}
// duplicates string into malloced block of memory
// first increment is to count size of s1
