/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:46:14 by sgaudin           #+#    #+#             */
/*   Updated: 2016/05/10 15:33:50 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			expose_hook(int x, int y, t_all *all)
{
	if (all->is_valid == JULIA)
	{
		printf("julia ok\n");
	}
	return (0);
}
