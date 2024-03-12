/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:35:28 by juhaamid          #+#    #+#             */
/*   Updated: 2023/12/19 19:00:29 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"


typedef struct s_img
{
	void			*img;
	char			*address;
	int				blood_pressure;
	int				length;
	int				endian;
	void			*mlx;
	void			*win;
	char	*nh;
	char	*sh;
	char	*wt;
	char	*et;
	int		p_x;
	int		p_y;
	char	**all;
}t_img;

typedef struct s_cub
{
	t_img	imaage;
	
}t_cub3d;


# ifdef __APPLE__
#  define ESC	53
#  define UP		126
#  define DOWN	125
#  define RIGHT	124
#  define LEFT	123
#  define ON_MOUSE_DW 4

# else
#  define ESC	65307
#  define MOUSE_UP 4
#  define MOUSE_DOWN 5
#  define UP	65362
#  define DOWN	65364
#  define RIGHT	65363
#  define LEFT 65361
#  define ON_MOUSE_DW 4
# endif



int	valid(char *file);
void	display(t_cub3d *cub);


#endif
