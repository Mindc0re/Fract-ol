/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 09:26:27 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/03 11:26:46 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		line(t_all *all)
{
	int		test_bits[4] = {WHITE, WHITE, WHITE, WHITE};
	int		size_line[1] = {500 * 4};
	int		endian[1] = {1};

	FT_INIT(int, i, 50);
	while (i < 200)
	{
		mlx_pixel_put(all->mlx, all->win, i, 200, all->color);
		i++;
	}
	all->img = mlx_get_data_addr(all->img_ptr, test_bits, size_line, endian);
	all->img[500] = 255;
	all->img[501] = 0;
	all->img[502] = 0;
	all->img[503] = 0;
	all->img[600] = 0;
	all->img[601] = 255;
	all->img[602] = 0;
	all->img[603] = 0;
	all->img[700] = 0;
	all->img[701] = 0;
	all->img[702] = 255;
	all->img[703] = 0;
	mlx_put_image_to_window(all->mlx, all->win, all->img_ptr, 250, 250);
}

int			key_hook(int keycode, t_all *all)
{
	if (keycode == ESC)
	{
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
	line(all);
	mlx_loop(all->mlx);
	return (0);
}
