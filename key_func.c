/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarriga <mdarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 15:45:22 by mdarriga          #+#    #+#             */
/*   Updated: 2015/01/20 17:50:20 by mdarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	left_key(t_env *e)
{
	e->old_dx = e->dirx;
	e->dirx = e->dirx * cos(0.05) - e->diry * sin(0.05);
	e->diry = e->old_dx * sin(0.05) + e->diry * cos(0.05);
	e->old_px = e->planex;
	e->planex = e->planex * cos(0.05) - e->planey * sin(0.05);
	e->planey = e->old_px * sin(0.05) + e->planey * cos(0.05);
	expose_hook(e);
}

void	up_key(t_env *e)
{
	if (e->map[(int)(e->posx + e->dirx * 0.2)][(int)e->posy] == 0)
		e->posx += e->dirx * 0.2;
	if (e->map[(int)e->posx][(int)(e->posy + e->diry * 0.2)] == 0)
		e->posy += e->diry * 0.2;
	expose_hook(e);
}

void	right_key(t_env *e)
{
	e->old_dx = e->dirx;
	e->dirx = e->dirx * cos(-0.05) - e->diry * sin(-0.05);
	e->diry = e->old_dx * sin(-0.05) + e->diry * cos(-0.05);
	e->old_px = e->planex;
	e->planex = e->planex * cos(-0.05) - e->planey * sin(-0.05);
	e->planey = e->old_px * sin(-0.05) + e->planey * cos(-0.05);
	expose_hook(e);
}

void	down_key(t_env *e)
{
	if (e->map[(int)(e->posx - e->dirx * 0.2)][(int)(e->posy)] == 0)
		e->posx -= e->dirx * 0.2;
	if (e->map[(int)(e->posx)][(int)(e->posy - e->diry * 0.2)] == 0)
		e->posy -= e->diry * 0.2;
	expose_hook(e);
}
