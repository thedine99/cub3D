/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:00:12 by ntan              #+#    #+#             */
/*   Updated: 2022/05/23 20:53:04 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	key_right(t_prog *cub3d)
{
	if (cub3d->map[(int)(cub3d->py + cub3d->pdx) / PXLS]
	[(int)(cub3d->px - cub3d->pdy) / PXLS] == '0'
	|| cub3d->map[(int)(cub3d->py + cub3d->pdx) / PXLS]
	[(int)(cub3d->px - cub3d->pdy) / PXLS] == '3')
	{
		cub3d->px -= cub3d->pdy / 5;
		cub3d->py += cub3d->pdx / 5;
	}
}

void	key_left(t_prog *cub3d)
{
	if (cub3d->map[(int)(cub3d->py - cub3d->pdx) / PXLS]
	[(int)(cub3d->px + cub3d->pdy) / PXLS] == '0'
	|| cub3d->map[(int)(cub3d->py - cub3d->pdx) / PXLS]
	[(int)(cub3d->px + cub3d->pdy) / PXLS] == '3')
	{
		cub3d->px += cub3d->pdy / 5;
		cub3d->py -= cub3d->pdx / 5;
	}
}

void	key_down(t_prog *cub3d)
{
	if (cub3d->map[(int)(cub3d->py - cub3d->pdy) / PXLS]
	[(int)(cub3d->px - cub3d->pdx) / PXLS] == '0'
	|| cub3d->map[(int)(cub3d->py - cub3d->pdy) / PXLS]
	[(int)(cub3d->px - cub3d->pdx) / PXLS] == '3')
	{
		cub3d->px -= cub3d->pdx / 5;
		cub3d->py -= cub3d->pdy / 5;
	}
}

void	key_up(t_prog *cub3d)
{
	if (cub3d->map[(int)(cub3d->py + cub3d->pdy) / PXLS]
	[(int)(cub3d->px + cub3d->pdx) / PXLS] == '0'
	|| cub3d->map[(int)(cub3d->py + cub3d->pdy) / PXLS]
	[(int)(cub3d->px + cub3d->pdx) / PXLS] == '3')
	{
		cub3d->px += cub3d->pdx / 5;
		cub3d->py += cub3d->pdy / 5;
	}
}
