/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 11:30:21 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/17 14:15:44 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/lib_draw_img.h"

static void			init_repere_julia(t_all *all)
{
	all->fractal->x_min = -1.344;
	all->fractal->x_max = all->fractal->x_min + ((all->win_x * 2.7) / 800);
	all->fractal->y_min = -1.2;
	all->fractal->y_max = all->fractal->y_min + ((all->win_y * 2.4) / 800);
}

static t_fractal	*init_julia(t_all *a)
{
	static int	check = 0;
	int			bits;
	int			endian;

	if (!check)
	{
		a->fractal = (t_fractal *)malloc(sizeof(t_fractal));
		a->fractal->c = (t_complex *)malloc(sizeof(t_complex));
		a->fractal->z = (t_complex *)malloc(sizeof(t_complex));
		init_repere_julia(a);
		a->fractal->iter_max = 50;
		a->img_ptr = mlx_new_image(a->mlx, a->win_x, a->win_y);
		a->img = mlx_get_data_addr(a->img_ptr, &bits, &a->sizeline, &endian);
		check++;
	}
	if (a->motion == PSYCHE)
	{
		a->fractal->c->r = a->fractal->pt_zoomx;
		a->fractal->c->i = a->fractal->pt_zoomy;
	}
	return (a->fractal);
}

static void			calcul_julia(t_all *a, t_fractal *j, double x, double y)
{
	j->z->r = (x / j->zoom_x + j->x_min);
	j->z->i = (y / j->zoom_y + j->y_min);
	FT_INIT(double, tmp, j->z->r);
	j->z->r = j->z->r * j->z->r -
		j->z->i * j->z->i + j->c->r;
	j->z->i = 2 * j->z->i * tmp + j->c->i;
	j->iter = 1;
	while ((j->z->r * j->z->r + j->z->i * j->z->i) < 4
			&& (j->iter < j->iter_max))
	{
		tmp = j->z->r;
		j->z->r = j->z->r * j->z->r -
			j->z->i * j->z->i + j->c->r;
		j->z->i = 2 * j->z->i * tmp + j->c->i;
		j->iter++;
	}
	if (j->iter == j->iter_max)
		put_pixel_img(x, y, WHITE, a);
	else
	{
		if (a->color_mode == NORMAL)
			put_pixel_img_degrade(x, y, a->color, a);
		else if (a->color_mode == PSYCHE)
			put_pixel_img_psyche(x, y, a);
	}
}

void				julia(t_all *all)
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
