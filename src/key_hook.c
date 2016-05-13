/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 09:57:40 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/13 15:18:30 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/lib_draw_img.h"

static void		inc_color(t_all *all)
{
	FT_INIT(int, r, (all->color & 0xFF0000) >> 16);
	FT_INIT(int, g, (all->color & 0x00FF00) >> 8);
	FT_INIT(int, b, (all->color & 0x0000FF));
	if (r < 250)
		r += 5;
	else if (g < 250)
		g += 5;
	else if (b < 250)
		b += 5;
	all->color = (r << 16) + (g << 8) + b;
}

static void		dec_color(t_all *all)
{
	FT_INIT(int, r, (all->color & 0xFF0000) >> 16);
	FT_INIT(int, g, (all->color & 0x00FF00) >> 8);
	FT_INIT(int, b, (all->color & 0x0000FF));
	if (r > 5)
		r -= 5;
	else if (g > 5)
		g -= 5;
	else if (b > 5)
		b -= 5;
	all->color = (r << 16) + (g << 8) + b;
}

static void		move_fractal(int k, t_all *all)
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

static void		key_hook_2(int keycode, t_all *all)
{
	all->fractal->iter_max += keycode == KP_MORE ? 10 : 0;
	if (keycode == KP_LESS)
		all->fractal->iter_max -= all->fractal->iter_max > 10 ? 10 : 0;
	else if (keycode == SPACE)
		all->color_mode = all->color_mode == NORMAL ? PSYCHE : NORMAL;
	else if (keycode == D)
		all->motion = all->motion == PSYCHE ? NORMAL : PSYCHE;
	else if (keycode == E)
		inc_color(all);
	else if (keycode == Q)
		dec_color(all);
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
	key_hook_2(keycode, all);
	move_fractal(keycode, all);
	choice("", all);
	return (0);
}
