/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:31:17 by juhaamid          #+#    #+#             */
/*   Updated: 2024/03/07 17:16:51 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	tex_free(t_cub3d *cub, t_image *tex)
{
	if (tex[N_TEXT].img)
		mlx_destroy_image(cub->mlx, tex[N_TEXT].img);
	if (tex[S_TEXT].img)
		mlx_destroy_image(cub->mlx, tex[S_TEXT].img);
	if (tex[W_TEXT].img)
		mlx_destroy_image(cub->mlx, tex[W_TEXT].img);
	if (tex[E_TEXT].img)
		mlx_destroy_image(cub->mlx, tex[E_TEXT].img);
}

int	close_window(t_cub3d *cub3d)
{
	if (cub3d->map.blocs && cub3d->map.blocs[0])
		ft_free_twod_array(cub3d->map.blocs);
	free_path_texture(cub3d);
	if (cub3d->text[N_TEXT].img)
		tex_free(cub3d, cub3d->text);
	if (cub3d->image.img != NULL)
	{
		mlx_destroy_image(cub3d->mlx, cub3d->image.img);
	}
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	printf("BYEEE!");
	exit(0);
}

int	keymove(t_cub3d *cub3d)
{
	if (cub3d->key.left)
		keyleft_handler(cub3d);
	if (cub3d->key.right)
		keyright_handler(cub3d);
	if (cub3d->key.w)
		keyw_handler(cub3d);
	if (cub3d->key.s)
		keys_handler(cub3d);
	if (cub3d->key.d)
		keyd_handler(cub3d);
	if (cub3d->key.a)
		keya_handler(cub3d);
	display(cub3d);
	return (0);
}

// changes bool value of key pressed then executes the movement
int	keypressed(int code, t_cub3d *cub3d)
{
	if (code == W_KEY)
		cub3d->key.w = true;
	else if (code == A_KEY)
		cub3d->key.a = true;
	else if (code == S_KEY)
		cub3d->key.s = true;
	else if (code == D_KEY)
		cub3d->key.d = true;
	else if (code == LEFT)
		cub3d->key.left = true;
	else if (code == RIGHT)
		cub3d->key.right = true;
	keymove(cub3d);
	return (0);
}

int	keyrelease(int code, t_cub3d *cub3d)
{
	if (code == ESC)
		close_window(cub3d);
	else if (code == SHOW_MAP)
		cub3d->show_map = !cub3d->show_map;
	else if (code == W_KEY)
		cub3d->key.w = false;
	else if (code == A_KEY)
		cub3d->key.a = false;
	else if (code == S_KEY)
		cub3d->key.s = false;
	else if (code == D_KEY)
		cub3d->key.d = false;
	else if (code == LEFT)
		cub3d->key.left = false;
	if (code == RIGHT)
		cub3d->key.right = false;
	return (0);
}
