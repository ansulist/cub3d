/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:19:44 by ansulist          #+#    #+#             */
/*   Updated: 2024/03/07 16:41:30 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_tex(t_cub3d *m)
{
	init_img(&m->text[N_TEXT]);
	init_img(&m->text[S_TEXT]);
	init_img(&m->text[E_TEXT]);
	init_img(&m->text[W_TEXT]);
}

void	init_img(t_image *img)
{
	img->img = NULL;
	img->address = NULL;
	img->bits_per_pixel = 0;
	img->size_line = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
	img->tex_x = 0;
	img->tex_y = 0;
}

void	tex_fill(t_cub3d *m, t_image *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(m->mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
	{
		printf("texture mlx to image failed");
		return ;
	}
	tex->address = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->size_line, &tex->endian);
}

// take path from main and use it to convert xpm
void	load_wall_textures(t_cub3d *cub3d)
{
	tex_fill(cub3d, &cub3d->text[N_TEXT], cub3d->textures.no);
	tex_fill(cub3d, &cub3d->text[S_TEXT], cub3d->textures.so);
	tex_fill(cub3d, &cub3d->text[E_TEXT], cub3d->textures.ea);
	tex_fill(cub3d, &cub3d->text[W_TEXT], cub3d->textures.we);
}
