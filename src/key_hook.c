/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 09:57:40 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/04 10:07:17 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/lib_draw_img.h"

int		key_hook(int keycode, t_all *all)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(all->mlx, all->img_ptr);
		if (all->mandel)
		{
			free(all->mandel->z);
			free(all->mandel->c);
			free(all->mandel);
		}
		free(all);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
