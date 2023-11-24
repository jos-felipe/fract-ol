/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:45:17 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/21 19:40:23 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

t_point	ft_middle(t_point a, t_point b)
{
	t_point	c;

	c.x = (a.x + b.x) / 2;
	c.y = (a.y + b.y) / 2;
	return (c);
}

void	ft_classic_artist(void *param)
{
	t_fractal	*fr;
	int			n;
	t_point		abc[3];

	fr = param;
	n = fr->iter_max;
	abc[0] = fr->pinsky.a;
	abc[1] = fr->pinsky.b;
	abc[2] = fr->pinsky.c;
	ft_sierpinsky(abc, n, fr);
}

void	ft_abc(t_fractal *fr)
{
	fr->pinsky.b.x = MARGIN * SIZE;
	fr->pinsky.b.y = SIZE - MARGIN * SIZE;
	fr->pinsky.a.x = SIZE / 2;
	fr->pinsky.a.y = MARGIN * SIZE;
	fr->pinsky.c.x = SIZE - MARGIN * SIZE;
	fr->pinsky.c.y = SIZE - MARGIN * SIZE;
}	

int	ft_pt_validation(t_point a)
{
	int	x_bool;
	int	y_bool;

	x_bool = (a.x < MARGIN * SIZE || a.x > SIZE - MARGIN * SIZE);
	y_bool = (a.y < MARGIN * SIZE || a.y > SIZE - MARGIN * SIZE);
	return (x_bool || y_bool);
}
