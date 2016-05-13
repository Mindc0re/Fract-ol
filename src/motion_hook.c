/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 13:53:43 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/13 15:40:39 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			motion_hook(int x_screen, int y_screen, t_all *a)
{
	if (a->is_valid == JULIA)
	{
		FT_INIT(double, x, x_screen);
		FT_INIT(double, y, y_screen);
		FT_INIT(double, dif_x, fabs(a->fractal->x_max - a->fractal->x_min));
		FT_INIT(double, dif_y, fabs(a->fractal->y_max - a->fractal->y_min));
		a->fractal->pt_zoomx = a->fractal->x_min + (dif_x / (a->win_x / x));
		a->fractal->pt_zoomy = a->fractal->y_min + (dif_y / (a->win_y / y));
		julia(a);
	}
	return (0);
}
