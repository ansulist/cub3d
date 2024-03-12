/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:16:31 by juhaamid          #+#    #+#             */
/*   Updated: 2022/10/31 08:19:36 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	j;

	j = 0;
	if (!s)
	{
		return ;
	}
	while (s[j])
	{
		(*f)(j, &s[j]);
		j++;
	}
}
// similar to strmapi but doesnt return a value
// or allocate space for new string
// simply applies the function to each char
