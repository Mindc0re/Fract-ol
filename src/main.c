/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 09:49:11 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/04 10:31:48 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/lib_draw_img.h"

int		main(void)
{
	t_all *all;

	all = (t_all *)malloc(sizeof(t_all));
	all->mlx = mlx_init();
	all->win_x = 500;
	all->win_y = 500;
	all->color = WHITE;
	all->win = mlx_new_window(all->mlx, all->win_x, all->win_y, "Fract'ol");
	mlx_hook(all->win, 2, (1L << 0), key_hook, all);
	mandelbrot(all);
	mlx_loop(all->mlx);
	return (0);
}
