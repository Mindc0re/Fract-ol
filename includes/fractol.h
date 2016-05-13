/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 09:29:26 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/13 15:28:30 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>

# include <stdio.h>

# define FT_INIT(t, n, v)			t n = v
# define FT_MULTI3(a, b, c)			a = b = c
# define FT_MULTI4(a, b, c, d)		a = b = c = d
# define FT_TER(si, alors, sinon)	si ? alors : sinon

# define WHITE 0xFFFFFF
# define RED 0xFF0921
# define BLUE 0x2C75FF
# define GREEN 0x3AF24B
# define PINK 0xF400A1
# define GOLD 0xFFD700
# define BLACK 0x000000

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
	ALT_R,
	SPACE = 49
}					keys;

enum {
	LEFT_B = 1,
	RIGHT_B,
	SIDE,
	ROLL_DOWN,
	ROLL_UP
}					mouse;

enum {
	MANDEL = 1,
	JULIA,
	SHIP
}					fractals;

enum {
	NORMAL = 1,
	PSYCHE
}					color_modes;

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
	int				is_valid;
	int				win_x;
	int				win_y;
	unsigned int	color;
	int				color_mode;
	int				motion;
	t_fractal		*fractal;
}					t_all;

int					key_hook(int keycode, t_all *all);
int					mouse_hook(int button, int x, int y, t_all *all);
int					motion_hook(int x_screen, int y_screen, t_all *all);
void				choice(char *str, t_all *all);

void				mandelbrot(t_all *all);
void				julia(t_all *all);
void				burning_ship(t_all *all);

#endif
