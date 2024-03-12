/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:05:53 by juhaamid          #+#    #+#             */
/*   Updated: 2022/11/02 14:38:29 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countword(char const *s, char c)
{
	unsigned int	i;
	int				cntr;

	i = 0;
	cntr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cntr++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (cntr);
}

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	bop;

	bop = 0;
	while (src[bop] != '\0' && bop < n)
	{
		dest[bop] = src[bop];
		bop++;
	}
	while (bop < n)
	{
		dest[bop] = '\0';
		bop++;
	}
	return (dest);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * n + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**temp;

	i = 0;
	k = 0;
	temp = (char **)malloc(sizeof(char *) * (countword(s, c) + 1));
	if (temp == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			temp[k] = ft_strndup(s + j, i - j);
			k++;
		}
	}
	temp[k] = NULL;
	return (temp);
}
//splits a string by a char as delimiter
//allocates space for split string
//countword is for the amount of words in str
//strndup modified to include len of the word to allocate
//strncpy copies string into strndup