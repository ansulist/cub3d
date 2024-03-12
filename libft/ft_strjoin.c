/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:13:41 by juhaamid          #+#    #+#             */
/*   Updated: 2022/11/02 12:40:11 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jstr;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	jstr = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!jstr)
		return (NULL);
	ft_strlcpy(jstr, s1, len1 + 1);
	ft_strlcat(jstr + (len1), s2, len2 + 1);
	return (jstr);
}
// joins two strings 
// first copies s1 into allocated string
// then concatenates s2 to A string