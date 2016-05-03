/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 14:45:11 by sgaudin           #+#    #+#             */
/*   Updated: 2016/04/15 09:45:34 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_line	*init_line(t_pt3d *s, t_pt3d *e, double inc[2])
{
	t_line *line;

	line = (t_line *)malloc(sizeof(t_line));
	line->start = (t_vector *)malloc(sizeof(t_vector));
	line->end = (t_vector *)malloc(sizeof(t_vector));
	line->start->x = s->x_2d;
	line->start->y = s->y_2d;
	line->end->x = e->x_2d;
	line->end->y = e->y_2d;
	line->inc_x = inc[0];
	line->inc_y = inc[1];
	return (line);
}

static int		line_2(t_line *line, double dx, double dy, t_all *all)
{
	double			cumul;
	int				i;

	FT_INIT(double, x, line->start->x);
	FT_INIT(double, y, line->start->y);
	i = 1;
	cumul = fabs(dy) / 2;
	while (i <= fabs(dy))
	{
		i++;
		y += line->inc_y;
		cumul += fabs(dx);
		if (cumul >= fabs(dy))
		{
			cumul -= fabs(dy);
			x += line->inc_x;
		}
		if (x >= 0 && x <= all->win_x && y >= 0 && y <= all->win_y)
			mlx_pixel_put(all->mlx, all->win, x, y, all->color);
	}
	return (0);
}

static int		line_1(t_line *line, double dx, double dy, t_all *all)
{
	double			cumul;
	int				i;

	FT_INIT(double, x, line->start->x);
	FT_INIT(double, y, line->start->y);
	i = 1;
	cumul = fabs(dx) / 2;
	while (i <= dx)
	{
		i++;
		x += line->inc_x;
		cumul += fabs(dy);
		if (cumul >= fabs(dx))
		{
			cumul -= fabs(dx);
			y += line->inc_y;
		}
		if (x >= 0 && x <= all->win_x && y >= 0 && y <= all->win_y)
			mlx_pixel_put(all->mlx, all->win, x, y, all->color);
	}
	return (0);
}

int				draw_line(t_pt3d *start, t_pt3d *end, t_all *all)
{
	double		inc[2];
	t_line		*line;

	FT_INIT(double, dx, end->x_2d - start->x_2d);
	FT_INIT(double, dy, end->y_2d - start->y_2d);
	inc[0] = dx < 0 ? -1 : 1;
	inc[1] = dy < 0 ? -1 : 1;
	if (!(line = init_line(start, end, inc)))
		return (-1);
	dx = fabs(dx);
	dy = fabs(dy);
	mlx_pixel_put(all->mlx, all->win, start->x_2d, start->y_2d, all->color);
	if (dx > dy)
		line_1(line, dx, dy, all);
	else
		line_2(line, dx, dy, all);
	free(line->start);
	free(line->end);
	free(line);
	return (0);
}
