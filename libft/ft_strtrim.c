/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:11:22 by juhaamid          #+#    #+#             */
/*   Updated: 2024/03/07 17:43:26 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	modified_ft_strchr(char c, const char *s)
{
	int		bop;

	bop = 0;
	while (s[bop] != '\0')
	{
		if (s[bop] == c)
			return (1);
		bop++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tstr;
	size_t	i;
	size_t	start;
	size_t	last;

	start = 0;
	last = ft_strlen(s1);
	while (s1[start] && modified_ft_strchr(s1[start], set))
		start++;
	while (last > start && modified_ft_strchr(s1[last - 1], set))
		last--;
	tstr = malloc(sizeof(char) * (last - start + 1));
	if (!tstr)
		return (NULL);
	i = 0;
	while (start < last)
		tstr[i++] = s1[start++];
	tstr[i] = '\0';
	return (tstr);
}
// trim string by a set of characters
// eg applebees with set as 'app'
// return will be 'lebees'
// strchr searches for set char in set string