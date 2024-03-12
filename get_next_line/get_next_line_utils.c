/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:15:19 by juhaamid          #+#    #+#             */
/*   Updated: 2024/03/07 17:44:58 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenn(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchrr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlenn(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	char	*str_res;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str_res = (char *)malloc(ft_strlenn(s1) + ft_strlenn(s2) + 1);
	if (str_res == NULL)
		return (NULL);
	ft_memmovee(str_res, s1, ft_strlenn(s1));
	ft_memmovee(str_res + ft_strlenn(s1), s2, ft_strlenn(s2));
	str_res[(ft_strlenn(s1) + ft_strlenn(s2))] = '\0';
	free(s1);
	return (str_res);
}

void	*ft_memmovee(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	if (dst == src)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	if (s < d)
	{
		i = 0;
		while (i < len)
		{
			d[len - 1 - i] = s[len - 1 - i];
			i++;
		}
		return (dst);
	}
	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_strdupp(char *s1)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(ft_strlenn(s1) + 1);
	if (str == 0)
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
