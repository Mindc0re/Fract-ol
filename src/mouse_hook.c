/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 13:44:22 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/06 12:43:45 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*static void		zoom_mandel(int b, int x, int y, t_all *all)
{
	if (b == ROLL_UP)
	{
		all->fractal->x_min = x - all->fractal->zoom_var;
		all->fractal->x_max = x + all->fractal->zoom_var;
		all->fractal->y_min = y - all->fractal->zoom_var;
		all->fractal->y_max = y + all->fractal->zoom_var;
	}
	else if (b == ROLL_DOWN)
	{
		all->fractal->x_min = x + all->fractal->zoom_var;
		all->fractal->x_max = x - all->fractal->zoom_var;
		all->fractal->y_min = y + all->fractal->zoom_var;
		all->fractal->y_max = y - all->fractal->zoom_var;
	}
}*/

int			mouse_hook(int button, int x, int y, t_all *all)
{
	static int init_rand = 0;

	if (button == ROLL_DOWN)
	{
		all->fractal->x_min -= 0.1;
		all->fractal->x_max += 0.1;
		all->fractal->y_min -= 0.1;
		all->fractal->y_max += 0.1;
		all->fractal->zoom_var += 0.1;
		if (all->fractal->iter_max > 5)
			all->fractal->iter_max -= 1;
//		zoom_mandel(button, x, y, all);
	}
	else if (button == ROLL_UP)
	{
		all->fractal->x_min += 0.1;
		all->fractal->x_max -= 0.1;
		all->fractal->y_min += 0.1;
		all->fractal->y_max -= 0.1;
		all->fractal->zoom_var -= 0.1;
		all->fractal->iter_max += 1;
//		zoom_mandel(button, x, y, all);
	}
/*	else if (button == LEFT_B)
	{
		if (init_rand++ == 0)
			srand(time(NULL));
		all->color = rand()%(0x00FFFFFF - 0x000A0A0A) + 0x000A0A0A;
		printf("%d\n", all->color);
		} */
//	julia(all);
	mandelbrot(all);
	return (0);
}
