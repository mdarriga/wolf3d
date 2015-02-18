/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarriga <mdarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 18:41:44 by mdarriga          #+#    #+#             */
/*   Updated: 2015/02/03 14:23:26 by mdarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "/usr/X11/include/X11/x.h"

# define BUFF_SIZE 1024
# define MAPW 24
# define MAPH 24
# define W 800
# define H 600
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define ESC 65307

typedef enum	e_action
{
	INIT,
	USE,
	DEL,
}				t_action;

typedef struct	s_img
{
	void		*ptr;
	char		*content;
	int			endian;
	size_t		line_size;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			**map;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			e2;
	int			err;
	int			color;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		old_dx;
	double		old_px;
	double		camerax;
	double		ray_px;
	double		ray_py;
	double		ray_dx;
	double		ray_dy;
	double		side_dx;
	double		side_dy;
	double		distx;
	double		disty;
	double		wall;
}				t_env;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

int				**ft_get_map(char *file, int i, int j, int **map);
int				expose_hook(t_env *e);
int				get_next_line(int const fd, char **line);
t_env			*init_var0(t_env *e, t_pos pos0, t_pos pos1);
t_env			init_var1(t_env e);
t_env			change_var2(t_env e, int x);
t_env			change_var3(t_env e);
t_env			change_var4(t_env e);
t_env			change_var5(t_env e);
void			ft_singleton(t_action order, t_env *e);
void			print_error(void);
void			draw_background(t_img *img);
void			up_key(t_env *e);
void			down_key(t_env *e);
void			right_key(t_env *e);
void			left_key(t_env *e);

#endif
