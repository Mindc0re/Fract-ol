/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 09:29:26 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/04 11:32:53 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>

# include <stdio.h>

# define FT_INIT(t, n, v)			t n = v
# define FT_MULTI(a, b, c)			a = b = c
# define FT_TER(si, alors, sinon)	si ? alors : sinon

# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define GREEN 0x0000FF00
# define PINK 0x00F400A1
# define GOLD 0x00FFD700

enum {
	ESC = 53,
	GAUCHE = 123,
	DROITE,
	BAS,
	HAUT,
	Q = 12,
	W,
	E,
	A = 0,
	S,
	D,
	R = 15,
	F = 3,
	H,
	KP_MORE = 69,
	KP_LESS = 78,
	KP_1 = 83,
	KP_2,
	KP_3,
	KP_4,
	KP_5,
	KP_6,
	KP_7,
	KP_8 = 91,
	KP_9,
	ALT_L = 261,
	ALT_R
}					keys;

typedef struct		s_complex
{
	float			r;
	float			i;
}					t_complex;

typedef struct		s_mandel
{
	float			zoom;
//	float			zoom_y;
	t_complex		*c;
	t_complex		*z;
	long int		iter;
	float			x_min;
	float			x_max;
	float			y_min;
	float			y_max;
}					t_mandel;

typedef struct		s_all
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	char			*img;
	int				win_x;
	int				win_y;
	int				color;
	t_mandel		*mandel;
}					t_all;

int					key_hook(int keycode, t_all *all);
void				mandelbrot(t_all *all);

#endif










