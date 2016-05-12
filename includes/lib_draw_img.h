/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_draw_img.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:38:18 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/12 12:42:38 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_DRAW_IMG_H
# define LIB_DRAW_IMG_H

# include "fractol.h"

void		put_pixel_img(int x, int y, unsigned int color, t_all *all);
void		put_pixel_img_degrade(int x, int y, unsigned int color, t_all *all);
void		put_pixel_img_psyche(int x, int y, t_all *all);

#endif
