/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarriga <mdarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 13:17:04 by mdarriga          #+#    #+#             */
/*   Updated: 2015/01/15 18:54:24 by mdarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_env	*init_var0(t_env *e, t_pos pos0, t_pos pos1)
{
	e->dx = fabs(pos0.x - pos0.x);
	e->sx = pos0.x < pos0.x ? 1 : -1;
	e->dy = fabs(pos1.y - pos0.y);
	e->sy = pos0.y < pos1.y ? 1 : -1;
	e->err = (e->dx > e->dy ? e->dx : -e->dy) / 2;
	return (e);
}

t_env	init_var1(t_env e)
{
	e.posx = 22;
	e.posy = 12;
	e.dirx = -1;
	e.diry = 0;
	e.planex = 0;
	e.planey = 0.66;
	return (e);
}

t_env	change_var2(t_env e, int x)
{
	e.camerax = 2 * x / (double)W - 1;
	e.ray_px = e.posx;
	e.ray_py = e.posy;
	e.ray_dx = e.dirx + e.planex * e.camerax;
	e.ray_dy = e.diry + e.planey * e.camerax;
	e.mapx = (int)e.ray_px;
	e.mapy = (int)e.ray_py;
	e.hit = 0;
	e.distx = sqrt(1 + (e.ray_dy * e.ray_dy) / (e.ray_dx * e.ray_dx));
	e.disty = sqrt(1 + (e.ray_dx * e.ray_dx) / (e.ray_dy * e.ray_dy));
	return (e);
}

t_env	change_var3(t_env e)
{
	if (e.ray_dx < 0)
	{
		e.stepx = -1;
		e.side_dx = (e.ray_px - e.mapx) * e.distx;
	}
	else
	{
		e.stepx = 1;
		e.side_dx = (e.mapx + 1.0 - e.ray_px) * e.distx;
	}
	if (e.ray_dy < 0)
	{
		e.stepy = -1;
		e.side_dy = (e.ray_py - e.mapy) * e.disty;
	}
	else
	{
		e.stepy = 1;
		e.side_dy = (e.mapy + 1.0 - e.ray_py) * e.disty;
	}
	return (e);
}

t_env	change_var4(t_env e)
{
	if (e.side_dx < e.side_dy)
	{
		e.side_dx += e.distx;
		e.mapx += e.stepx;
		e.side = 0;
	}
	else
	{
		e.side_dy += e.disty;
		e.mapy += e.stepy;
		e.side = 1;
	}
	if (e.map[e.mapx][e.mapy] > 0)
		e.hit = 1;
	return (e);
}
