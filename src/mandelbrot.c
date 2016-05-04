/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:35:28 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/04 11:46:51 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/lib_draw_img.h"

#define ITER_MAX 30

static t_mandel	*init_mandel(t_all *all)
{
	all->mandel = (t_mandel *)malloc(sizeof(t_mandel));
	all->mandel->c = (t_complex *)malloc(sizeof(t_complex));
	all->mandel->z = (t_complex *)malloc(sizeof(t_complex));
	all->mandel->y_min = -1.2;
	all->mandel->y_max = 1.2;
	all->mandel->x_min = -2.1;
	all->mandel->x_max = 0.6;
	all->mandel->zoom = 100;
	return (all->mandel);
}

static void		calcul_itermax(t_all *all, t_mandel *mandel, int x, int y)
{
	FT_INIT(double, tmp, 0);
	mandel->c->r = x / mandel->zoom + mandel->x_min;
	mandel->c->i = y / mandel->zoom + mandel->y_min;
	mandel->z->r = 0;
	mandel->z->i = 0;
	mandel->iter = 0;
/*	tmp = mandel->z->r;
	mandel->z->r = mandel->z->r * mandel->z->r -
				mandel->z->i * mandel->z->i + mandel->c->r;
	mandel->z->i = 2 * mandel->z->i * tmp + mandel->c->i;
	mandel->iter++; */
	do{
		tmp = mandel->z->r;
		mandel->z->r = mandel->z->r * mandel->z->r +
						mandel->z->i * mandel->z->i + mandel->c->r;
		mandel->z->i = 2 * mandel->z->i * tmp + mandel->c->i;
		mandel->iter++;
	}while ((mandel->z->r * mandel->z->r + mandel->z->i * mandel->z->i) < 4
			   && (mandel->iter < ITER_MAX));
	if (mandel->iter == ITER_MAX)
		put_pixel_img(x, y, all->color, all);
}

void			mandelbrot(t_all *all)
{
	int bits;
	int size;
	int endian;
	FT_INIT(t_mandel, *mandel, init_mandel(all));
	FT_INIT(float, img_x, (mandel->x_max - mandel->x_min) * mandel->zoom);
	FT_INIT(float, img_y, (mandel->y_max - mandel->y_min) * mandel->zoom);
//	mandel->zoom_x = all->win_x / (mandel->x_max - mandel->x_min);
//	mandel->zoom_y = all->win_y / (mandel->y_max - mandel->y_min);
	FT_INIT(int, x, 0);
	FT_INIT(int, y, 0);
	all->img_ptr = mlx_new_image(all->mlx, all->win_x, all->win_y);
	all->img = mlx_get_data_addr(all->img_ptr, &bits, &size, &endian);
	while (x < img_x)
	{
		y = 0;
		while (y < img_y)
		{
			calcul_itermax(all, mandel, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img_ptr, 0, 0);
}
