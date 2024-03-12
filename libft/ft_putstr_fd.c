/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:11:29 by juhaamid          #+#    #+#             */
/*   Updated: 2022/11/01 09:19:57 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	pop;

	pop = 0;
	while (s[pop] != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
// outputs string to file descriptor