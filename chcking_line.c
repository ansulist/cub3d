/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chcking_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:17:09 by ansulist          #+#    #+#             */
/*   Updated: 2024/03/07 17:23:25 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_lines(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (cub3d->map.blocs[i] != NULL)
	{
		j = 0;
		while (cub3d->map.blocs[i][j] != '\0')
		{
			if (cub3d->map.blocs[i][j] == 'N'
				|| cub3d->map.blocs[i][j] == 'S'
					|| cub3d->map.blocs[i][j] == 'E'
						|| cub3d->map.blocs[i][j] == 'W')
				cub3d->player_position = cub3d->map.blocs[i][j];
			j++;
		}
		i++;
	}
	return (0);
}
