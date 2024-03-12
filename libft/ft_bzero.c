/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:18:02 by juhaamid          #+#    #+#             */
/*   Updated: 2022/11/01 16:29:58 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	m;

	str = (char *)s;
	m = 0;
	while (m < n)
	{
		str[m] = 0;
		m++;
	}
}
// fills block of memory with 0
// within n bytes
// could be used to initialize variables
