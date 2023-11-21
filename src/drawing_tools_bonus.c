/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_tools_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:48:30 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/21 19:38:42 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	ft_draw_triangle(t_fractal *fr, t_point a, t_point b, t_point c)
{
	ft_bresenham(a, b, fr);
	ft_bresenham(b, c, fr);
	ft_bresenham(c, a, fr);
}

void	ft_bresenham_h(t_point a, int32_t dx, int32_t dy, t_fractal *fr)
{
	int32_t	i;
	int32_t	dis;

	i = 0;
	dis = (2 * abs(dy)) - abs(dx);
	while (i++ < abs(dx))
	{
		if (dx < 0)
			a.x = a.x - 1;
		else
			a.x = a.x + 1;
		if (dis < 0)
			dis = dis + 2 * abs(dy);
		else
		{
			if (dy < 0)
				a.y = a.y - 1;
			else
				a.y = a.y + 1;
			dis = dis + 2 * (abs(dy) - abs(dx));
		}
		if (!ft_pt_validation(a))
			mlx_put_pixel(fr->canvas, a.x, a.y, 0xFFFFFFF);
	}
}

void	ft_bresenham_v(t_point a, int32_t dx, int32_t dy, t_fractal *fractal)
{
	int32_t	dis;
	int32_t	i;

	i = 0;
	dis = (2 * abs(dx)) - abs(dy);
	while (i++ < abs(dy))
	{
		if (dy < 0)
			a.y = a.y - 1;
		else
			a.y = a.y + 1;
		if (dis < 0)
			dis = dis + 2 * abs(dx);
		else
		{
			if (dx < 0)
				a.x = a.x - 1;
			else
				a.x = a.x + 1;
			dis = dis + 2 * (abs(dx) - abs(dy));
		}
		if (!ft_pt_validation(a))
			mlx_put_pixel(fractal->canvas, a.x, a.y, 0xFFFFFFFF);
	}
}

void	ft_bresenham(t_point a, t_point b, t_fractal *fractal)
{
	int32_t	dx;
	int32_t	dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (abs(dx) > abs(dy))
		ft_bresenham_h(a, dx, dy, fractal);
	else
		ft_bresenham_v(a, dx, dy, fractal);
}
