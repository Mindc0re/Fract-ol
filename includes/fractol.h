/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 09:29:26 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/09 16:20:03 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <time.h>

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
# define BLACK 0x00000000

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

enum {
	LEFT_B = 1,
	RIGHT_B,
	ROLL_DOWN = 4,
	ROLL_UP
}					mouse;

typedef struct		s_complex
{
	double			r;
	double			i;
}					t_complex;

typedef struct		s_fractal
{
	double			zoom_x;
	double			zoom_y;
	double			pt_zoomx;
	double			pt_zoomy;
	t_complex		*c;
	t_complex		*z;
	double			iter;
	double			iter_max;
	double			x_min;
	double			x_max;
	double			y_min;
	double			y_max;
}					t_fractal;

typedef struct		s_all
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	char			*img;
	int				win_x;
	int				win_y;
	unsigned int	color;
	t_fractal		*fractal;
}					t_all;

int					key_hook(int keycode, t_all *all);
int					mouse_hook(int button, int x, int y, t_all *all);
void				mandelbrot(t_all *all);
void				julia(t_all *all);

#endif
