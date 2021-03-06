/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:26:39 by ntan              #+#    #+#             */
/*   Updated: 2022/05/21 20:51:32 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	update(t_prog *cub3d)
{
	void	*tmp;

	tmp = cub3d->tmp_img.image;
	newimage(cub3d);
	raycasting(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->tmp_img.image, 0, 0);
	if (tmp)
		mlx_destroy_image(cub3d->mlx, tmp);
	return (0);
}

int	game_loop(t_prog *cub3d)
{
	cub3d->pdx = cos(cub3d->pa) * 5;
	cub3d->pdy = sin(cub3d->pa) * 5;
	cub3d->plane_x = cos(cub3d->pa + PI / 2) * 5;
	cub3d->plane_y = sin(cub3d->pa + PI / 2) * 5;
	cub3d->mlx = mlx_init();
	if (!cub3d->mlx)
		return (1);
	cub3d->minimap_ext = create_sprite(cub3d, cub3d->mlx, "srcs/game/11.xpm");
	cub3d->minimap_int = create_sprite(cub3d, cub3d->mlx, "srcs/game/12.xpm");
	cub3d->no_text_img = create_sprite(cub3d, cub3d->mlx, cub3d->no_text);
	cub3d->so_text_img = create_sprite(cub3d, cub3d->mlx, cub3d->so_text);
	cub3d->we_text_img = create_sprite(cub3d, cub3d->mlx, cub3d->we_text);
	cub3d->ea_text_img = create_sprite(cub3d, cub3d->mlx, cub3d->ea_text);
	init_window(cub3d, 1280, 720, "cub3d");
	mlx_do_key_autorepeaton(cub3d->mlx);
	mlx_hook(cub3d->win, 17, 0, ending, cub3d);
	mlx_hook(cub3d->win, 2, (1L << 0), input, cub3d);
	mlx_loop(cub3d->mlx);
	return (0);
}
