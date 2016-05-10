/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 11:30:21 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/10 12:35:34 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/lib_draw_img.h"

t_fractal		*init_julia(t_all *all)
{
	static int	check = 0;
	int			bits;
	int			size;
	int			endian;

	if (!check)
	{
		all->fractal = (t_fractal *)malloc(sizeof(t_fractal));
		all->fractal->c = (t_complex *)malloc(sizeof(t_complex));
		all->fractal->z = (t_complex *)malloc(sizeof(t_complex));
		all->fractal->y_min = (-1.2 * all->win_y) / 240;
		all->fractal->y_max = (1.2 * all->win_y) / 240;
		all->fractal->x_min = (-1 * all->win_x) / 200;
		all->fractal->x_max = (1 * all->win_x) / 200;
		all->fractal->iter_max = 50;
		all->fractal->c->r = 0.285;
		all->fractal->c->i = 0.01;
		all->img_ptr = mlx_new_image(all->mlx, all->win_x, all->win_y);
		all->img = mlx_get_data_addr(all->img_ptr, &bits, &size, &endian);
		check++;
	}
	return (all->fractal);
}

void			calcul_julia(t_all *all, t_fractal *julia, double x, double y)
{
	double tmp;

	julia->z->r = x / julia->zoom_x + julia->x_min;
	julia->z->i = y / julia->zoom_y + julia->y_min;
	julia->iter = 0;
	tmp = julia->z->r;
	julia->z->r = julia->z->r * julia->z->r -
		julia->z->i * julia->z->i + julia->c->r;
	julia->z->i = 2 * julia->z->i * tmp + julia->c->i;
	julia->iter++;
	while ((julia->z->r * julia->z->r + julia->z->i * julia->z->i) < 4
			&& (julia->iter < julia->iter_max))
	{
		tmp = julia->z->r;
		julia->z->r = julia->z->r * julia->z->r -
			julia->z->i * julia->z->i + julia->c->r;
		julia->z->i = 2 * julia->z->i * tmp + julia->c->i;
		julia->iter++;
	}
	if (julia->iter == julia->iter_max)
		put_pixel_img(x, y, BLACK, all);
	else
		put_pixel_img_degrade(x, y, all->color, all);
}

void			julia(t_all *all)
{
	FT_INIT(t_fractal, *julia, init_julia(all));
	FT_INIT(double, x, 0);
	FT_INIT(double, y, 0);
	julia->zoom_x = all->win_x / (all->fractal->x_max - all->fractal->x_min);
	julia->zoom_y = all->win_y / (all->fractal->y_max - all->fractal->y_min);
	while (x < all->win_x)
	{
		y = 0;
		while (y < all->win_y)
		{
			calcul_julia(all, julia, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img_ptr, 0, 0);
}
