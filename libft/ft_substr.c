/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:42:51 by ansulist          #+#    #+#             */
/*   Updated: 2024/03/07 17:43:13 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			substr[j++] = s[i];
		i++;
	}
	substr[j] = '\0';
	return (substr);
}
//allocates space for substr and returns it
// begins at 'start' ends at 'len'
// searches for the str & mallocs & assigns return for it