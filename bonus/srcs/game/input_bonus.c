/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:47:07 by ntan              #+#    #+#             */
/*   Updated: 2022/05/21 21:56:28 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	left_arrow(t_prog *cub3d, double angle)
{
	cub3d->pa -= angle;
	if (cub3d->pa < 0)
		cub3d->pa += 2 * PI;
	cub3d->pdx = cos(cub3d->pa) * 4;
	cub3d->pdy = sin(cub3d->pa) * 4;
	cub3d->plane_x = cos(cub3d->pa + PI / 2) * 4;
	cub3d->plane_y = sin(cub3d->pa + PI / 2) * 4;
	update(cub3d);
}

void	right_arrow(t_prog *cub3d, double angle)
{
	cub3d->pa += angle;
	if (cub3d->pa > 2 * PI)
		cub3d->pa -= 2 * PI;
	cub3d->pdx = cos(cub3d->pa) * 4;
	cub3d->pdy = sin(cub3d->pa) * 4;
	cub3d->plane_x = cos(cub3d->pa + PI / 2) * 4;
	cub3d->plane_y = sin(cub3d->pa + PI / 2) * 4;
	update(cub3d);
}

int	input(int key, t_prog *cub3d)
{
	if (key == ESC || key == 65307)
		ending(cub3d);
	else if (key == KEY_UP)
		key_up(cub3d);
	else if (key == KEY_DOWN)
		key_down(cub3d);
	else if (key == KEY_LEFT)
		key_left(cub3d);
	else if (key == KEY_RIGHT)
		key_right(cub3d);
	else if (key == RIGHT_ARROW)
		right_arrow(cub3d, 0.1);
	else if (key == LEFT_ARROW)
		left_arrow(cub3d, 0.1);
	return (0);
}