/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 13:44:22 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/13 14:32:39 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/lib_draw_img.h"

static void		zoom_fractal(int b, double x, double y, t_all *all)
{
	FT_INIT(double, diff_x, fabs(all->fractal->x_max - all->fractal->x_min));
	FT_INIT(double, diff_y, fabs(all->fractal->y_max - all->fractal->y_min));
	all->fractal->pt_zoomx = all->fractal->x_min + (diff_x / (all->win_x / x));
	all->fractal->pt_zoomy = all->fractal->y_min + (diff_y / (all->win_y / y));
	if (b == ROLL_DOWN)
	{
		all->fractal->x_min -= diff_x / 10;
		all->fractal->x_max += diff_x / 10;
		all->fractal->y_min -= diff_y / 10;
		all->fractal->y_max += diff_y / 10;
	}
	if (b == ROLL_UP || b == LEFT_B)
	{
		all->fractal->x_min = all->fractal->pt_zoomx - (diff_x / 2);
		all->fractal->y_min = all->fractal->pt_zoomy - (diff_y / 2);
		all->fractal->x_max = all->fractal->pt_zoomx + (diff_x / 2);
		all->fractal->y_max = all->fractal->pt_zoomy + (diff_y / 2);
		all->fractal->x_min += diff_x / 10;
		all->fractal->x_max -= diff_x / 10;
		all->fractal->y_min += diff_y / 10;
		all->fractal->y_max -= diff_y / 10;
	}
}

int				mouse_hook(int button, int x, int y, t_all *all)
{
	if (button == ROLL_DOWN)
	{
		if (all->fractal->iter_max > 5)
			all->fractal->iter_max -= 2;
		zoom_fractal(button, x, y, all);
	}
	else if (button == ROLL_UP || LEFT_B)
		all->fractal->iter_max += 2;
	zoom_fractal(button, x, y, all);
	choice("", all);
	return (0);
}
