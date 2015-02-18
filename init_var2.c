/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarriga <mdarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 15:37:55 by mdarriga          #+#    #+#             */
/*   Updated: 2015/01/19 15:33:05 by mdarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_env			change_var5(t_env e)
{
	if (e.side == 0)
		e.wall = fabs((e.mapx - e.ray_px + (1 - e.stepx) / 2) / e.ray_dx);
	else
		e.wall = fabs((e.mapy - e.ray_py + (1 - e.stepy) / 2) / e.ray_dy);
	e.line_height = fabs((int)(H / e.wall));
	e.draw_start = -e.line_height / 2 + H / 2;
	if (e.draw_start < 0)
		e.draw_start = 0;
	e.draw_end = e.line_height / 2 + H / 2;
	if (e.draw_end >= H)
		e.draw_end = H - 1;
	if (e.side == 0 && e.ray_dx > 0)
		e.color = 0xff00ff;
	else if (e.side == 0 && e.ray_dx < 0)
		e.color = 0xeeee00;
	if (e.side == 1 && e.ray_dy > 0)
		e.color = 0x00ee00;
	else if (e.side == 1 && e.ray_dy < 0)
		e.color = 0x0000ee;
	return (e);
}
