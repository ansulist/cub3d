/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:00:57 by juhaamid          #+#    #+#             */
/*   Updated: 2022/10/31 08:17:22 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*new_str;
	size_t	j;

	new_str = ft_strdup(s);
	if (!new_str)
		return (NULL);
	j = 0;
	while (new_str[j])
	{
		new_str[j] = (*f)(j, new_str[j]);
		j++;
	}
	return (new_str);
}
// applies function to each char of string
// index or count thingy is first arg
// uses strdup to malloc space for new_str