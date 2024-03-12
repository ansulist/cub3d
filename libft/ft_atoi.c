/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:36:53 by juhaamid          #+#    #+#             */
/*   Updated: 2022/11/02 11:16:52 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int			neg;
	long int	nbr;
	int			bop;

	neg = 1;
	nbr = 0;
	bop = 0;
	while ((nptr[bop] == ' ' || (nptr[bop] >= 9 && nptr[bop] <= 13)))
		bop++;
	if (nptr[bop] == '-' || nptr[bop] == '+')
	{
		if (nptr[bop] == '-')
			neg *= -1;
		bop++;
	}
	while (nptr[bop] >= '0' && nptr[bop] <= '9')
	{
		nbr = nbr * 10 + nptr[bop] - '0';
		bop++;
		if (nbr > 1844674407370955169 && neg == 1)
			return (-1);
		if (nbr > 1844674407370955169 && neg == -1)
			return (0);
	}
	return (neg * nbr);
}
// super large number is unsigned long limit
// converts numbers in a string to integer