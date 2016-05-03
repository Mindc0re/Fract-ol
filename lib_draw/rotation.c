/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:04:21 by sgaudin           #+#    #+#             */
/*   Updated: 2016/04/11 17:04:18 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

int			rotation_x(t_all *all)
{
	static int		angle = 290;

	all->cam->cam_pos->x = all->midmap->x
		+ (30 * opcos(opmod(angle, 360)));
	all->cam->cam_pos->z = all->midmap->x
		+ (30 * opsin(opmod(angle, 360)));
	all->cam->cam_ang->y = opmod(all->cam->cam_ang->y - all->rotation->x, 360);
	angle += all->rotation->x;
	return (0);
}

int			rotation_y(t_all *all)
{
	static int		angle = 180;

	all->cam->cam_pos->y = all->midmap->y
		+ (30 * opsin(opmod(angle, 360)));
	all->cam->cam_pos->z = all->midmap->y
		+ (30 * opcos(opmod(angle, 360)));
	all->cam->cam_ang->x = opmod(all->cam->cam_ang->x - all->rotation->y, 360);
	angle += all->rotation->y;
	return (0);
}
