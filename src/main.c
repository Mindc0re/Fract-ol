/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 09:49:11 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/17 14:12:02 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/lib_draw_img.h"

static void		color_choice(char *str, t_all *all)
{
	ft_strtolower(str);
	if (!ft_strcmp(str, "red"))
		all->color = RED;
	else if (!ft_strcmp(str, "blue"))
		all->color = BLUE;
	else if (!ft_strcmp(str, "green"))
		all->color = GREEN;
	else if (!ft_strcmp(str, "gold"))
		all->color = GOLD;
	else if (!ft_strcmp(str, "pink"))
		all->color = PINK;
	else
		all->color = 13971711;
}

static void		init_mlx(char *str, t_all *all)
{
	ft_strtolower(str);
	if (!ft_strcmp(str, "mandelbrot") || !ft_strcmp(str, "julia")
		|| !ft_strcmp(str, "burning_ship"))
	{
		all->mlx = mlx_init();
		all->win_x = 1980;
		all->win_y = 1080;
		all->color_mode = NORMAL;
		all->motion = PSYCHE;
		all->win = mlx_new_window(all->mlx, all->win_x, all->win_y, "Fract'ol");
		mlx_hook(all->win, 2, (1L << 0), key_hook, all);
		mlx_hook(all->win, 6, (1L << 6), motion_hook, all);
		mlx_mouse_hook(all->win, mouse_hook, all);
	}
}

int				choice(char *str, t_all *all)
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
		return (0);
	return (1);
}

int				main(int ac, char **av)
{
	t_all *all;

	if (ac >= 2)
	{
		all = (t_all *)malloc(sizeof(t_all));
		all->is_valid = 0;
		if (ac == 3)
			color_choice(av[2], all);
		else
			color_choice("", all);
		if (!choice(av[1], all))
		{
			free(all);
			ft_putendl("Correct fractals : mandelbrot, julia, burning_ship");
			ft_putendl("Correct colors : green, blue, red, pink, gold");
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		ft_putendl("Correct fractals : mandelbrot, julia, burning_ship");
		ft_putendl("Correct colors : green, blue, red, pink, gold");
	}
	return (0);
}
