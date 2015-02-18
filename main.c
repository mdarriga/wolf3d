/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarriga <mdarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 18:49:44 by mdarriga          #+#    #+#             */
/*   Updated: 2015/01/20 17:38:25 by mdarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		line(t_env *e, t_pos pos0, t_pos pos1)
{
	e = init_var0(e, pos0, pos1);
	while (42)
	{
		mlx_pixel_put(e->mlx, e->win, pos0.x, pos0.y, e->color);
		if (pos0.x == pos0.x && pos0.y == pos1.y)
			break ;
		e->e2 = e->err;
		if (e->e2 > -e->dx)
		{
			e->err -= e->dy;
			pos0.x += e->sx;
		}
		if (e->e2 < e->dy)
		{
			e->err += e->dx;
			pos0.y += e->sy;
		}
	}
}

static void	draw_env(t_env e)
{
	t_pos	pos0;
	t_pos	pos1;
	int		x;

	x = 0;
	while (x++ < W)
	{
		e = change_var2(e, x);
		e = change_var3(e);
		while (e.hit == 0)
			e = change_var4(e);
		e = change_var5(e);
		pos0.x = x;
		pos0.y = e.draw_start;
		pos1.y = e.draw_end;
		line(&e, pos0, pos1);
	}
}

int			expose_hook(t_env *e)
{
	ft_singleton(USE, e);
	draw_env(*e);
	return (0);
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == UP)
		up_key(e);
	if (keycode == DOWN)
		down_key(e);
	if (keycode == RIGHT)
		right_key(e);
	if (keycode == LEFT)
		left_key(e);
	return (0);
}

int			main(int ac, char **av)
{
	t_env	e;

	e = init_var1(e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, W, H, "Wolf3D - Mdarriga");
	if (av[1] != 0 && ac)
		e.map = ft_get_map(av[1], 0, 0, e.map);
	else
		print_error();
	ft_singleton(INIT, &e);
	mlx_hook(e.win, KeyPress, KeyPressMask, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
