/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 13:44:22 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/05 15:06:56 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			mouse_hook(int button, int x, int y, t_all *all)
{
	static int init_rand = 0;

	if (button == ROLL_UP)
	{
		all->mandel->x_min -= 1;
		all->mandel->x_max -= 1;
		all->mandel->y_min -= 1;
		all->mandel->x_max -= 1;
	}
	else if (button == ROLL_DOWN)
	{
		all->mandel->x_min += 1;
		all->mandel->x_max += 1;
		all->mandel->y_min += 1;
		all->mandel->x_max += 1;
	}
	else if (button == LEFT_B)
	{
		if (init_rand++ == 0)
			srand(time(NULL));
		all->color = rand()%(0xFFFFFF - 0x010101) + 0x010101;
	}
	mandelbrot(all);
	return (0);
}
