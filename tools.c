/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarriga <mdarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 14:08:10 by mdarriga          #+#    #+#             */
/*   Updated: 2015/01/16 12:48:15 by mdarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	print_pixel(t_img *img, int x, int y, int color)
{
	img->content[(img->line_size * y) + 4 * x + (img->endian ? 3 : 0)] =
		(color & 0x000000FF) >> 000;
	img->content[(img->line_size * y) + 4 * x + (img->endian ? 2 : 1)] =
		(color & 0x0000FF00) >> 010;
	img->content[(img->line_size * y) + 4 * x + (img->endian ? 1 : 2)] =
		(color & 0x00FF0000) >> 020;
}

void	draw_background(t_img *img)
{
	int x;
	int y;

	y = 0;
	while (y < H / 2)
	{
		x = 0;
		while (x < W)
		{
			print_pixel(img, x, y, 0x33CCFF);
			x++;
		}
		y++;
	}
	while (y <= H)
	{
		x = 0;
		while (x < W)
		{
			print_pixel(img, x, y, 0x663333);
			x++;
		}
		y++;
	}
}

void	ft_singleton(t_action order, t_env *e)
{
	static t_img	*img;
	int				endian;
	int				line_size;
	int				bit;

	if (order == INIT)
	{
		img = (t_img *)malloc(sizeof(t_img));
		img->ptr = mlx_new_image(e->mlx, W, H);
		img->content = mlx_get_data_addr(img->ptr, &bit, &line_size, &endian);
		img->endian = endian;
		img->line_size = line_size;
		draw_background(img);
	}
	if (order == USE)
		mlx_put_image_to_window(e->mlx, e->win, img->ptr, 0, 0);
	if (order == DEL)
		free(img);
}
