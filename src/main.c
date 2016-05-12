/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 09:49:11 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/12 13:10:58 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/lib_draw_img.h"

static void		init_mlx(char *str, t_all *all)
{
	ft_strtolower(str);
	if (!ft_strcmp(str, "mandelbrot") || !ft_strcmp(str, "julia")
		|| !ft_strcmp(str, "burning_ship"))
	{
		all->mlx = mlx_init();
		all->win_x = 800;
		all->win_y = 800;
		all->color = 13971711;
		all->color_mode = NORMAL;
		all->win = mlx_new_window(all->mlx, all->win_x, all->win_y, "Fract'ol");
		mlx_hook(all->win, 2, (1L << 0), key_hook, all);
		mlx_mouse_hook(all->win, mouse_hook, all);
	}
}

void			choice(char *str, t_all *all)
{
	if (!all->is_valid)
		init_mlx(str, all);
	if (!ft_strcmp(str, "mandelbrot") || all->is_valid == MANDEL)
	{
		all->is_valid = MANDEL;
		mandelbrot(all);
		mlx_loop(all->mlx);
	}
	else if (!ft_strcmp(str, "julia") || all->is_valid == JULIA)
	{
		all->is_valid = JULIA;
		julia(all);
		mlx_loop(all->mlx);
	}
	else if (!ft_strcmp(str, "burning_ship") || all->is_valid == SHIP)
	{
		all->is_valid = SHIP;
		burning_ship(all);
		mlx_loop(all->mlx);
	}
	else
	{
		ft_putendl("Correct fractals : mandelbrot, julia, burning_ship");
		free(all);
	}
}

int				main(int ac, char **av)
{
	t_all *all;

	if (ac == 2)
	{
		all = (t_all *)malloc(sizeof(t_all));
		all->is_valid = 0;
		choice(av[1], all);
	}
	else
		ft_putendl("Correct fractals : mandelbrot, julia, burning_ship");
	return (0);
}
