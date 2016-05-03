/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 09:29:26 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/03 15:58:39 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
/* TMP */
# include <stdio.h>
/* TMP */

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

typedef struct		s_all
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	char			*img;
	int				win_x;
	int				win_y;
	int				color;
}					t_all;

typedef struct		s_complex
{
	double			r;
	double			i;
}					t_complex;

typedef struct		s_mandel
{
	long long int	zoom;
	t_complex		*c;
	t_complex		*z;
	long int		iter;
}					t_mandel;

#endif
