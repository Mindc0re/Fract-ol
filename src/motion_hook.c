/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 13:53:43 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/13 14:07:45 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			motion_hook(int x_screen, int y_screen, t_all *all)
{
	if (all->is_valid == JULIA)
	{
		FT_INIT(double, x, x_screen);
		FT_INIT(double, y, y_screen);
		FT_INIT(double, diff_x, fabs(all->fractal->x_max - all->fractal->x_min));
		FT_INIT(double, diff_y, fabs(all->fractal->y_max - all->fractal->y_min));
		all->fractal->pt_zoomx = all->fractal->x_min + (diff_x / (all->win_x / x));
		all->fractal->pt_zoomy = all->fractal->y_min + (diff_y / (all->win_y / y));
		julia(all);
	}
	return (0);
}
