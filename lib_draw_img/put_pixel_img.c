/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 13:03:30 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/05 14:33:25 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		put_pixel_img(int x, int y, unsigned int color, t_all *all)
{
	if (x >= 0 && x <= all->win_x && y >= 0 && y <= all->win_y)
	{
		all->img[(x * 4) + (y * (all->win_y * 4))] = (color & 0x0000FF);
		all->img[(x * 4) + 1 + (y * (all->win_y * 4))] = (color & 0x00FF00) >> 8;
		all->img[(x * 4) + 2 + (y * (all->win_y * 4))] = (color & 0xFF0000) >> 16;
		all->img[(x * 4) + 3 + (y * (all->win_y * 4))] = 0;
	}
}

void		put_pixel_img_degrade(int x, int y, double i, t_all *all)
{
	unsigned int color;

	if (x >= 0 && x <= all->win_x && y >= 0 && y <= all->win_y)
	{
		color = all->color;
		all->img[(x * 4) + (y * (all->win_y * 4))] = (i * (color & 0x0000FF)) / all->mandel->iter_max;
		all->img[(x * 4) + 1 + (y * (all->win_y * 4))] = (i * ((color & 0x00FF00) >> 8)) / all->mandel->iter_max;
		all->img[(x * 4) + 2 + (y * (all->win_y * 4))] = (i * ((color & 0xFF0000) >> 16)) / all->mandel->iter_max;
		all->img[(x * 4) + 3 + (y * (all->win_y * 4))] = 0;
	}
}
