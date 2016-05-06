/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 09:57:40 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/06 12:45:13 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/lib_draw_img.h"

int		key_hook(int keycode, t_all *all)
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
	else if (keycode == GAUCHE)
	{
		all->fractal->x_min -= 0.05;
		all->fractal->x_max -= 0.05;
	}
	else if (keycode == DROITE)
	{
		all->fractal->x_min += 0.05;
		all->fractal->x_max += 0.05;
	}
	else if (keycode == BAS)
	{
		all->fractal->y_min += 0.05;
		all->fractal->y_max += 0.05;
	}
	else if (keycode == HAUT)
	{
		all->fractal->y_min -= 0.05;
		all->fractal->y_max -= 0.05;
	}
	else if (keycode == F)
		all->fractal->iter_max += 0.5;
//	julia(all);
	mandelbrot(all);
	return (0);
}
