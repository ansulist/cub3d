/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:19:46 by juhaamid          #+#    #+#             */
/*   Updated: 2022/10/28 09:30:52 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	m;

	m = 0;
	while (m < n)
	{
		if (s1[m] != s2[m])
			return ((unsigned char)s1[m] - (unsigned char)s2[m]);
		else if (s1[m] == '\0' && s2[m] == '\0')
			return (0);
		m++;
	}
	return (0);
}
// compares two strings