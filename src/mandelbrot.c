/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:35:28 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/05 14:53:46 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/lib_draw_img.h"


static t_mandel	*init_mandel(t_all *all)
{
	static int check = 0;
	if (check == 0)
	{
		all->mandel = (t_mandel *)malloc(sizeof(t_mandel));
		all->mandel->c = (t_complex *)malloc(sizeof(t_complex));
		all->mandel->z = (t_complex *)malloc(sizeof(t_complex));
		all->mandel->y_min = -1.2;
		all->mandel->y_max = 1.2;
		all->mandel->x_min = -2.1;
		all->mandel->x_max = 0.6;
		check++;
	}
	all->mandel->iter_max = 50;
	return (all->mandel);
}

static void		calcul_itermax(t_all *all, t_mandel *mandel, double x, double y)
{
	double	tmp;
	mandel->c->r = (x / mandel->zoom_x) + mandel->x_min;
	mandel->c->i = (y / mandel->zoom_y) + mandel->y_min;
	mandel->z->r = 0;
	mandel->z->i = 0;
	mandel->iter = 0;
	tmp = mandel->z->r;
	mandel->z->r = mandel->z->r * mandel->z->r -
				mandel->z->i * mandel->z->i + mandel->c->r;
	mandel->z->i = 2 * mandel->z->i * tmp + mandel->c->i;
	mandel->iter++;
	while ((mandel->z->r * mandel->z->r + mandel->z->i * mandel->z->i) < 4
					   && (mandel->iter < mandel->iter_max))
	{
		tmp = mandel->z->r;
		mandel->z->r = mandel->z->r * mandel->z->r -
						mandel->z->i * mandel->z->i + mandel->c->r;
		mandel->z->i = 2 * mandel->z->i * tmp + mandel->c->i;
		mandel->iter++;
	}
	if (mandel->iter == mandel->iter_max)
		put_pixel_img(x, y, BLACK, all);
	else
		put_pixel_img_degrade(x, y, all->mandel->iter, all);
}

void			mandelbrot(t_all *all)
{
	int bits;
	int size;
	int endian;
	FT_INIT(t_mandel, *mandel, init_mandel(all));
	mandel->zoom_x = all->win_x / (all->mandel->x_max - all->mandel->x_min);
	mandel->zoom_y = all->win_y / (all->mandel->y_max - all->mandel->y_min);
	FT_INIT(double, x, 0);
	FT_INIT(double, y, 0);
	all->img_ptr = mlx_new_image(all->mlx, all->win_x, all->win_y);
	all->img = mlx_get_data_addr(all->img_ptr, &bits, &size, &endian);
	while (x < all->win_x)
	{
		y = 0;
		while (y < all->win_y)
		{
			calcul_itermax(all, mandel, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img_ptr, 0, 0);
}
