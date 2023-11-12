/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:38:05 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/11 20:12:21 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Mathematical models for fractal sets

#include "../include/fractol.h"

uint32_t	ft_mandelbrot(t_fractal *fractal, t_complex *c)
{
	double		xtemp;
	t_complex	z;
	uint32_t	color;
	int32_t		i;

	z.x = 0;
	z.y = 0;
	i = 0;
	while (i < fractal->iter_max)
	{
		xtemp = z.x * z.x - z.y * z.y + c->x;
		z.y = 2 * z.x * z.y + c->y;
		z.x = xtemp;
		if (z.x * z.x + z.y * z.y > 4)
			break ;
		i++;
	}
	if (i == fractal->iter_max)
		color = ft_pixel(0x00, 0x00, 0x00, 0xFF);
	else
		// color = ft_bernstein_poly(i, fractal);
		color = ft_bernstein_poly(1.0 * i / fractal->iter_max, fractal->rgb);
	return (color);
}

uint32_t	ft_julia(t_fractal *fractal, t_complex *z)
{
	double		xtemp;
	uint32_t	color;
	int32_t		i;

	i = 0;
	while (i < fractal->iter_max)
	{
		xtemp = z->x * z->x - z->y * z->y;
		z->y = 2 * z->x * z->y + fractal->c.y;
		z->x = xtemp + fractal->c.x;
		if (z->x * z->x + z->y * z->y > 4)
			break ;
		i++;
	}
	if (i == fractal->iter_max)
		color = ft_pixel(0x00, 0x00, 0x00, 0xFF);
	else
		color = ft_bernstein_poly(i, fractal);
	return (color);
}

void	julia_sets(t_complex *c, int i)
{
	t_complex	tmp[4];

	ft_complex(&tmp[0], -0.7, 0.27015);
	ft_complex(&tmp[1], 0.285, 0.01);
	ft_complex(&tmp[2], -0.8, 0.156);
	ft_complex(&tmp[3], 0.4, 0.4);
	if (i < 0 || i > 3)
		return ;
	c->x = tmp[i].x;
	c->y = tmp[i].y;
}
