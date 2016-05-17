/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 13:03:30 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/17 14:04:50 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		put_pixel_img(int x, int y, unsigned int c, t_all *all)
{
	if (x >= 0 && x <= all->win_x && y >= 0 && y <= all->win_y)
	{
		all->img[(x * 4) + (y * all->sizeline)] = (c & 0x0000FF);
		all->img[(x * 4) + 1 + (y * all->sizeline)] = (c & 0x00FF00) >> 8;
		all->img[(x * 4) + 2 + (y * all->sizeline)] = (c & 0xFF0000) >> 16;
		all->img[(x * 4) + 3 + (y * all->sizeline)] = 0;
	}
}

void		put_pixel_img_degrade(int x, int y, unsigned int c, t_all *all)
{
	double			i;

	if (x >= 0 && x <= all->win_x && y >= 0 && y <= all->win_y)
	{
		i = all->fractal->iter;
		all->img[(x * 4) + (y * all->sizeline)] = (i * (c & 0x0000FF))
			/ all->fractal->iter_max;
		all->img[(x * 4) + 1 + (y * all->sizeline)] =
			(i * ((c & 0x00FF00) >> 8)) / all->fractal->iter_max;
		all->img[(x * 4) + 2 + (y * all->sizeline)] =
			(i * ((c & 0xFF0000) >> 16)) / all->fractal->iter_max;
		all->img[(x * 4) + 3 + (y * all->sizeline)] = 0;
	}
}

void		put_pixel_img_psyche(int x, int y, t_all *a)
{
	static int	tab[300] = { 0 };
	int			i;

	if (x >= 0 && x <= a->win_x && y >= 0 && y <= a->win_y)
	{
		i = a->fractal->iter - 1;
		if (i < 0 || i > 299)
			i = rand() % 300;
		if (!tab[i])
			tab[i] = rand() % 16581375;
		a->img[(x * 4) + (y * a->sizeline)] = (tab[i] & 0x0000FF);
		a->img[(x * 4) + 1 + (y * a->sizeline)] = (tab[i] & 0x00FF00) >> 8;
		a->img[(x * 4) + 2 + (y * a->sizeline)] = (tab[i] & 0xFF0000) >> 16;
		a->img[(x * 4) + 3 + (y * a->sizeline)] = 0;
	}
}
