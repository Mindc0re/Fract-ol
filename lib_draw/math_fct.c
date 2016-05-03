/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 14:46:53 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/31 14:33:02 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double		opcos(double n)
{
	static double	*list;
	int				i;

	if (!list)
	{
		list = (double *)malloc(sizeof(double) * 360);
		i = -1;
		while (++i < 360)
			list[i] = cosf(i * 2 * M_PI / 360);
	}
	return (list[(int)n % 360]);
}

double		opsin(double n)
{
	static double	*list;
	int				i;

	if (!list)
	{
		list = (double *)malloc(sizeof(double) * 360);
		i = -1;
		while (++i < 360)
			list[i] = sinf(i * 2 * M_PI / 360);
	}
	return (list[(int)n % 360]);
}

double		opmod(double n, double base)
{
	return (n < 0.0 ? fmod(((fmod(n, base)) + base), base) : fmod(n, base));
}
