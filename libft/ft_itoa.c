/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:55:22 by juhaamid          #+#    #+#             */
/*   Updated: 2022/10/31 13:06:34 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_check(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*itoa_str;
	long int	numero;
	int			i;

	numero = n;
	i = digit_check(numero);
	itoa_str = malloc(sizeof(char) * i + 1);
	if (!itoa_str)
		return (NULL);
	itoa_str[i] = '\0';
	if (numero == 0)
	{
		itoa_str[0] = '0';
	}
	if (numero < 0)
	{
		itoa_str[0] = '-';
		numero = numero * -1;
	}
	while (numero > 0)
	{
		itoa_str[--i] = numero % 10 + '0';
		numero = numero / 10;
	}
	return (itoa_str);
}
// converts int into string?
// digit check for amount of digits in n