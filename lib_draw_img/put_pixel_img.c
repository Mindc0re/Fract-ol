/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 13:03:30 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/12 12:23:49 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		put_pixel_img(int x, int y, unsigned int c, t_all *all)
{
	if (x >= 0 && x <= all->win_x && y >= 0 && y <= all->win_y)
	{
		all->img[(x * 4) + (y * (all->win_y * 4))] = (c & 0x0000FF);
		all->img[(x * 4) + 1 + (y * (all->win_y * 4))] = (c & 0x00FF00) >> 8;
		all->img[(x * 4) + 2 + (y * (all->win_y * 4))] = (c & 0xFF0000) >> 16;
		all->img[(x * 4) + 3 + (y * (all->win_y * 4))] = 0;
	}
}

void		put_pixel_img_degrade(int x, int y, unsigned int c, t_all *all)
{
	double			i;

	if (x >= 0 && x <= all->win_x && y >= 0 && y <= all->win_y)
	{
		i = all->fractal->iter;
		all->img[(x * 4) + (y * (all->win_y * 4))] = (i * (c & 0x0000FF))
			/ all->fractal->iter_max;
		all->img[(x * 4) + 1 + (y * (all->win_y * 4))] =
			(i * ((c & 0x00FF00) >> 8)) / all->fractal->iter_max;
		all->img[(x * 4) + 2 + (y * (all->win_y * 4))] =
			(i * ((c & 0xFF0000) >> 16)) / all->fractal->iter_max;
		all->img[(x * 4) + 3 + (y * (all->win_y * 4))] = 0;
	}
}
