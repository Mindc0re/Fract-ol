/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:35:28 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/03 16:03:50 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/lib_draw_img.h"

#define X_MIN -2.1
#define X_MAX 0.6
#define Y_MIN -1.2
#define Y_MAX 1.2
#define ITER_MAX 50

static t_mandel		*init_mandel(void)
{
	t_mandel		*mandel;

	mandel = (t_mandel *)malloc(sizeof(t_mandel));
	mandel->c = (t_complex *)malloc(sizeof(t_complex));
	mandel->z = (t_complex *)malloc(sizeof(t_complex));
	mandel->zoom = 100;
	mandel->c->r = X_MIN;
	mandel->c->i = Y_MIN;
	mandel->z->r = 0;
	mandel->z->i = 0;
	mandel->iter = 0;
	return (mandel);
}

void				mandelbrot(t_all *all)
{
	FT_INIT(t_mandel, *mandel, init_mandel());
	FT_INIT(double, img_x, (X_MAX - X_MIN) * mandel->zoom_mandel);
	FT_INIT(double, img_y, (Y_MAX - Y_MIN) * mandel->zoom_mandel);
	FT_INIT(int, x, 0);
	FT_INIT(int, y, 0);
	FT_INIT(double, tmp, 0);
	while (x < img_x)
	{
		while (y < img_y)
		{
			mandel->c->r = x / mandel->zoom + X_MIN;
			mandel->c->i = y / mandel->zoom + Y_MIN;
			mandel->z->r = 0;
			mandel->z->i = 0;
			mandel->iter = 0;
			tmp = mandel->z->r;
			y++;
		}
		x++;
	}
}
