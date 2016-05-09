/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 09:57:40 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/09 15:33:49 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/lib_draw_img.h"

static	void	move_fractal(int k, t_all *all)
{
	FT_INIT(double, diff_x, fabs(all->fractal->x_max - all->fractal->x_min));
	FT_INIT(double, diff_y, fabs(all->fractal->y_max - all->fractal->y_min));
	if (k == GAUCHE)
	{
		all->fractal->x_min -= diff_x / 50;
		all->fractal->x_max -= diff_x / 50;
	}
	else if (k == DROITE)
	{
		all->fractal->x_min += diff_x / 50;
		all->fractal->x_max += diff_x / 50;
	}
	else if (k == BAS)
	{
		all->fractal->y_min += diff_x / 50;
		all->fractal->y_max += diff_x / 50;
	}
	else if (k == HAUT)
	{
		all->fractal->y_min -= diff_x / 50;
		all->fractal->y_max -= diff_x / 50;
	}
}

int				key_hook(int keycode, t_all *all)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(all->mlx, all->img_ptr);
		if (all->fractal)
		{
			free(all->fractal->z);
			free(all->fractal->c);
			free(all->fractal);
		}
		free(all);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == F)
		all->fractal->iter_max += 0.5;
//	julia(all);
	move_fractal(keycode, all);
	mandelbrot(all);
	return (0);
}
