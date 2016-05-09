/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:35:28 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/09 16:06:27 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/lib_draw_img.h"

static t_fractal	*init_mandel(t_all *all)
{
	static int check = 0;
	int bits;
	int size;
	int endian;

	if (!check)
	{
		all->fractal = (t_fractal *)malloc(sizeof(t_fractal));
		all->fractal->c = (t_complex *)malloc(sizeof(t_complex));
		all->fractal->z = (t_complex *)malloc(sizeof(t_complex));
		all->fractal->y_min = (-1.2 * all->win_y) / 240;
		all->fractal->y_max = (1.2 * all->win_y) / 240;
		all->fractal->x_min = (-2.1 * all->win_x) / 270;
		all->fractal->x_max = (0.6 * all->win_x) / 270;
		all->fractal->iter_max = 25;
		all->img_ptr = NULL;
		check++;
	}
	if (all->img_ptr)
		mlx_destroy_image(all->mlx, all->img_ptr);
	all->img_ptr = mlx_new_image(all->mlx, all->win_x, all->win_y);
	all->img = mlx_get_data_addr(all->img_ptr, &bits, &size, &endian);
	return (all->fractal);
}

static void			calcul_mandel(t_all *all, t_fractal *mandel, double x, double y)
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
		put_pixel_img_degrade(x, y, all->color, all);
}

void				mandelbrot(t_all *all)
{
	FT_INIT(t_fractal, *mandel, init_mandel(all));
	FT_INIT(double, x, 0);
	FT_INIT(double, y, 0);
	mandel->zoom_x = all->win_x / (all->fractal->x_max - all->fractal->x_min);
	mandel->zoom_y = all->win_y / (all->fractal->y_max - all->fractal->y_min);
	while (x < all->win_x)
	{
		y = 0;
		while (y < all->win_y)
		{
			calcul_mandel(all, mandel, x, y);
			y++;
		}
		x++;
	}
	mlx_clear_window(all->mlx, all->win);
	mlx_put_image_to_window(all->mlx, all->win, all->img_ptr, 0, 0);
	mlx_pixel_put(all->mlx, all->win, 250, 250, RED);
}
