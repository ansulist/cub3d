/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:35:08 by juhaamid          #+#    #+#             */
/*   Updated: 2024/03/07 17:08:50 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_key(t_cub3d *cub3d)
{
	cub3d->key.w = 0;
	cub3d->key.a = 0;
	cub3d->key.s = 0;
	cub3d->key.d = 0;
	cub3d->key.left = 0;
	cub3d->key.right = 0;
}

void	init_most_elements(t_cub3d *cub3d)
{
	check_plane_for_player(cub3d);
	check_direction_for_player(cub3d);
	init_image(cub3d);
	init_key(cub3d);
	init_tex(cub3d);
	load_wall_textures(cub3d);
	display(cub3d);
}

// key movements for the player
void	setup_hooks(t_cub3d *cub3d)
{
	mlx_hook(cub3d->win, 17, 0, close_window, cub3d);
	mlx_hook(cub3d->win, 2, (1L << 0), keypressed, cub3d);
	mlx_hook(cub3d->win, 3, (1L << 1), keyrelease, cub3d);
	mlx_loop_hook(cub3d->mlx, &keymove, cub3d);
}

// dispaying it on the window
// for the window
// for the pixel of the game and the player
void	display(t_cub3d *cub3d)
{
	t_image	texture;

	mlx_clear_window(cub3d->mlx, cub3d->win);
	setup_hooks(cub3d);
	reset_image(cub3d);
	draw_cieling(cub3d, cub3d->color_c);
	draw_floor(cub3d, cub3d->color_f);
	raycast(cub3d, &texture);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->image.img, 0, 0);
}

int	main(int ac, char **av)
{
	t_cub3d	cub3d;

	if (check_ac_av(ac, av) == -1)
		return (1);
	init_cub3d(&cub3d);
	if (load_config_from_file(av[1], &cub3d) == -1)
	{
		printf("PARSING ERROR, CHECK AGAIN PLEASE\n");
		return (1);
	}
	printf("LOAD CONFIG FROM FILE GOOD\n");
	cub3d.mlx = mlx_init();
	cub3d.win = mlx_new_window(cub3d.mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y,
			"junita's & anita's cub3d <3");
	init_most_elements(&cub3d);
	mlx_loop(cub3d.mlx);
	return (0);
}
