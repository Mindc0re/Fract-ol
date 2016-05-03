/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 09:26:27 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/03 14:37:44 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/lib_draw_img.h"

void		wtf(t_all *all)
{
	int		bits;
	int		size;
	int		endian;
	unsigned int color = RED;

	FT_INIT(int, i, 0);
	FT_INIT(int, j, 0);
	all->img = mlx_get_data_addr(all->img_ptr, &bits, &size, &endian);
	while (j < all->win_y)
	{
		i = 0;
		while (i < all->win_x)
		{
			put_pixel_img(i, j, color, all);
			i++;
//			color += i;
		}
		j++;
//		color += j;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img_ptr, 0, 0);
}

int			key_hook(int keycode, t_all *all)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(all->mlx, all->img_ptr);
		free(all);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int			main(void)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	all->mlx = mlx_init();
	all->win_x = 500;
	all->win_y = 500;
	all->color = WHITE;
	all->img_ptr = mlx_new_image(all->mlx, all->win_x, all->win_y);
	all->win = mlx_new_window(all->mlx, all->win_x, all->win_y, "TEEEEEEEST");
	mlx_hook(all->win, 2, (1L << 0), key_hook, all);
	wtf(all);
	mlx_loop(all->mlx);
	return (0);
}
