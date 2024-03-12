/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:05:18 by ansulist          #+#    #+#             */
/*   Updated: 2024/03/07 16:47:55 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Parse color in RGB format into a HEX code
int	parse_rgb_color(char *color, int *hex_color)
{
	char	**splitted;
	int		nb;
	int		i;

	if (color == NULL)
		return (-1);
	splitted = ft_split(color, ',');
	if (splitted == NULL || splitted[0] == NULL
		|| splitted[1] == NULL || splitted[2] == NULL)
		return (-1);
	*hex_color = 0;
	i = 0;
	while (i < 3)
	{
		nb = ft_atoi(splitted[i]);
		if (nb < 0 || nb > 255)
			return (-1);
		*hex_color = *hex_color | ft_atoi(splitted[i]) << (2 - i) * 8;
		i++;
	}
	return (0);
}

// Load one color from the file
// Mutate hex_color with the loaded color
// Return 0 if good, -1 if fails
int	load_color(int fd, char *id, int *hex_color)
{
	char	*line;
	char	**splitted;
	int		ret;

	line = get_next_line(fd);
	if (line == NULL)
		return (-1);
	splitted = ft_split(line, ' ');
	free(line);
	if (splitted == NULL)
		return (-1);
	if (splitted[0] == NULL || ft_strncmp(splitted[0], id, ft_strlen(id)) != 0)
	{
		ft_free_twod_array(splitted);
		return (-1);
	}
	if (splitted[1] == NULL)
		return (-1);
	ret = parse_rgb_color(splitted[1], hex_color);
	ft_free_twod_array(splitted);
	return (ret);
}
