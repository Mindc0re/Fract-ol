/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 13:44:22 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/09 16:55:32 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/lib_draw_img.h"

static void		zoom_fractal(int b, double x, double y, t_all *all)
{
	FT_INIT(double, diff_x, fabs(all->fractal->x_max - all->fractal->x_min));
	FT_INIT(double, diff_y, fabs(all->fractal->y_max - all->fractal->y_min));

	if (b == ROLL_UP)
	{
		all->fractal->x_min += diff_x / 10;
		all->fractal->x_max -= diff_x / 10;
		all->fractal->y_min += diff_y / 10;
		all->fractal->y_max -= diff_y / 10;
	}
	else if (b == ROLL_DOWN)
	{
		all->fractal->x_min -= diff_x / 10;
		all->fractal->x_max += diff_x / 10;
		all->fractal->y_min -= diff_y / 10;
		all->fractal->y_max += diff_y / 10;
	}
	else if (b == LEFT_B)
	{
		all->fractal->pt_zoomx = (all->fractal->x_max / (all->win_x / x));
		all->fractal->pt_zoomy = (all->fractal->y_max / (all->win_y / y));
		printf("PARAM DEBUT : x_min = %f, x_max = %f, y_min = %f, y_max = %f\n",
			   all->fractal->x_min, all->fractal->x_max, all->fractal->y_min, all->fractal->y_max);
		printf("CLIC : (%f ; %f) correspond a (%f ; %f) dans le repere\n",
			   x, y, all->fractal->pt_zoomx, all->fractal->pt_zoomy);
		all->fractal->x_min = all->fractal->pt_zoomx - (all->fractal->x_max / 2);
		all->fractal->y_min = all->fractal->pt_zoomy - (all->fractal->y_max / 2);
		all->fractal->x_max = all->fractal->pt_zoomx + (all->fractal->x_max / 2);
		all->fractal->y_max = all->fractal->pt_zoomy + (all->fractal->y_max / 2);
	}
}

int			mouse_hook(int button, int x, int y, t_all *all)
{
	static int init_rand = 0;

	if (button == ROLL_DOWN)
	{
		if (all->fractal->iter_max > 5)
			all->fractal->iter_max -= 2;
		zoom_fractal(button, x, y, all);
	}
	else if (button == ROLL_UP)
	{
		all->fractal->iter_max += 2;
		zoom_fractal(button, x, y, all);
	}
/*	else if (button == LEFT_B)
	{
		if (init_rand++ == 0)
			srand(time(NULL));
		all->color = rand()%(0x00FFFFFF - 0x000A0A0A) + 0x000A0A0A;
		printf("%d\n", all->color);
		} */
//	julia(all);
	zoom_fractal(button, x, y, all);
	mandelbrot(all);
	return (0);
}
