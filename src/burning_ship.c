/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:58:35 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/12 11:12:53 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/lib_draw_img.h"

static t_fractal	*init_ship(t_all *all)
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
/*		all->fractal->y_min = (-1.2 * all->win_y) / 240;
		all->fractal->y_max = (1.2 * all->win_y) / 240;
		all->fractal->x_min = (-2.1 * all->win_x) / 270;
		all->fractal->x_max = (0.6 * all->win_x) / 270;
*/
		all->fractal->y_min = -1.2;
		all->fractal->y_max = 1.2;
		all->fractal->x_min = -2.1;
		all->fractal->x_max = 0.6;

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

static void			ship_calc(t_all *all, t_fractal *ship, double x, double y)
{
	double	tmp;

	ship->c->r = (x / ship->zoom_x) + ship->x_min;
	ship->c->i = (y / ship->zoom_y) + ship->y_min;
	FT_MULTI4(ship->z->r, ship->z->i, ship->iter, 0);
/*	ship->z->r = 0;
	ship->z->i = 0;
	ship->iter = 0; */
	ship->z->r = fabs(ship->z->r);
	ship->z->i = fabs(ship->z->i);
	tmp = ship->z->r;
	ship->z->r = ship->z->r * ship->z->r -
		ship->z->i * ship->z->i + ship->c->r;
	ship->z->i = 2 * ship->z->i * tmp + ship->c->i;
	ship->iter++;
	while ((ship->z->r * ship->z->r + ship->z->i * ship->z->i) < 4
		   && (ship->iter < ship->iter_max))
	{
		ship->z->r = fabs(ship->z->r);
		ship->z->i = fabs(ship->z->i);
		tmp = ship->z->r;
		ship->z->r = ship->z->r * ship->z->r -
			ship->z->i * ship->z->i + ship->c->r;
		ship->z->i = 2 * ship->z->i * tmp + ship->c->i;
		ship->iter++;
	}
	if (ship->iter == ship->iter_max)
		put_pixel_img(x, y, BLACK, all);
	else
		put_pixel_img_degrade(x, y, all->color, all);
}

void		burning_ship(t_all *all)
{
	FT_INIT(t_fractal, *ship, init_ship(all));
	FT_INIT(double, x, 0);
	FT_INIT(double, y, 0);
	ship->zoom_x = all->win_x / (all->fractal->x_max - all->fractal->x_min);
	ship->zoom_y = all->win_y / (all->fractal->y_max - all->fractal->y_min);
	while (x < all->win_x)
	{
		y = 0;
		while (y < all->win_y)
		{
			ship_calc(all, ship, x, y);
			y++;
		}
		x++;
	}
	mlx_clear_window(all->mlx, all->win);
	mlx_put_image_to_window(all->mlx, all->win, all->img_ptr, 0, 0);
	mlx_pixel_put(all->mlx, all->win, all->win_x / 2, all->win_y / 2, RED);
}










