/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:40:28 by ntan              #+#    #+#             */
/*   Updated: 2022/05/21 20:50:03 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ending(t_prog *cub3d)
{
	if (cub3d->minimap_ext.image)
		mlx_destroy_image(cub3d->mlx, cub3d->minimap_ext.image);
	if (cub3d->minimap_int.image)
		mlx_destroy_image(cub3d->mlx, cub3d->minimap_int.image);
	if (cub3d->tmp_img.image)
		mlx_destroy_image(cub3d->mlx, cub3d->tmp_img.image);
	if (cub3d->ea_text_img.image)
		mlx_destroy_image(cub3d->mlx, cub3d->ea_text_img.image);
	if (cub3d->we_text_img.image)
		mlx_destroy_image(cub3d->mlx, cub3d->we_text_img.image);
	if (cub3d->so_text_img.image)
		mlx_destroy_image(cub3d->mlx, cub3d->so_text_img.image);
	if (cub3d->no_text_img.image)
		mlx_destroy_image(cub3d->mlx, cub3d->no_text_img.image);
	if (cub3d->win)
		mlx_destroy_window(cub3d->mlx, cub3d->win);
	mlx_destroy_display(cub3d->mlx);
	free(cub3d->mlx);
	memrelease();
	exit(0);
}

t_image	create_sprite(t_prog *cub3d, void *mlx, char *path)
{
	t_image	sprite;

	sprite.image = mlx_xpm_file_to_image(mlx, path, &sprite.size_x,
			&sprite.size_y);
	if (!sprite.image)
	{
		printf("Error\nAn image is missing\n");
		ending(cub3d);
	}
	sprite.addr = mlx_get_data_addr(sprite.image, &sprite.bits_per_pixel,
			&sprite.line_length, &sprite.endian);
	return (sprite);
}

void	init_window(t_prog *cub3d, int widht, int height, char *name)
{
	cub3d->win = mlx_new_window(cub3d->mlx, widht, height, name);
	cub3d->win_x = widht;
	cub3d->win_y = height;
	update(cub3d);
}
