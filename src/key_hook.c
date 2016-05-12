/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 09:57:40 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/12 12:03:24 by sgaudin          ###   ########.fr       */
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
		all->fractal->y_min += diff_y / 50;
		all->fractal->y_max += diff_y / 50;
	}
	else if (k == HAUT)
	{
		all->fractal->y_min -= diff_x / 50;
		all->fractal->y_max -= diff_x / 50;
	}
}

int				key_hook(int keycode, t_all *all)
{
	static int neg = 0;

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
	{
		all->fractal->iter_max += neg == 0 ? 0.5 : -0.5;
		neg = neg == 0 ? 1 : 0;
	}
	all->fractal->iter_max += keycode == KP_MORE ? 10 : 0;
	if (keycode == KP_LESS)
		all->fractal->iter_max -= all->fractal->iter_max > 10 ? 10 : 0;
	move_fractal(keycode, all);
	choice("", all);
	return (0);
}
