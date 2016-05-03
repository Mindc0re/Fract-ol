/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:14:19 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/03 09:55:46 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_DRAW_H
# define LIB_DRAW_H

# include "fdf.h"

int				conversion3d(t_pt3d *point, t_all *all);

double			opcos(double n);
double			opsin(double n);
double			opmod(double n, double base);

int				rotation_x(t_all *all);
int				rotation_y(t_all *all);

int				draw_line(t_pt3d *start, t_pt3d *end, t_all *all);
int				draw_map_x(t_all *all);

#endif
