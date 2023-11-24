/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:38:05 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/21 20:40:03 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Mathematical models for fractal sets

#include "../include/fractol.h"

uint32_t	ft_mandelbrot(t_fractal *fractal, t_complex *c)
{
	double			xtemp;
	t_complex		z;
	uint32_t		color;
	unsigned int	i;

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
		color = ft_bernstein_poly(1.0 * i / fractal->iter_max, fractal->rgb);
	return (color);
}

uint32_t	ft_julia(t_fractal *fractal, t_complex *z)
{
	double			xtemp;
	uint32_t		color;
	unsigned int	i;

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
		color = ft_bernstein_poly(1.0 * i / fractal->iter_max, fractal->rgb);
	return (color);
}

void	ft_sierpinsky(t_point abc[], int n, t_fractal *fr)
{
	t_point	tmp[3];

	tmp[0] = abc[0];
	tmp[1] = abc[1];
	tmp[2] = abc[2];
	if (n > 0)
	{
		ft_draw_triangle(fr, tmp[0], tmp[1], tmp[2]);
		abc[0] = tmp[0];
		abc[1] = ft_middle(tmp[0], tmp[1]);
		abc[2] = ft_middle(tmp[0], tmp[2]);
		ft_sierpinsky(abc, n - 1, fr);
		abc[0] = ft_middle(tmp[0], tmp[1]);
		abc[1] = tmp[1];
		abc[2] = ft_middle(tmp[1], tmp[2]);
		ft_sierpinsky(abc, n - 1, fr);
		abc[0] = ft_middle(tmp[0], tmp[2]);
		abc[1] = ft_middle(tmp[1], tmp[2]);
		abc[2] = tmp[2];
		ft_sierpinsky(abc, n - 1, fr);
	}
}

t_complex	ft_julia_set_c(char i)
{
	t_complex	tmp[5];
	t_complex	c;

	ft_complex(&tmp[0], -0.7, 0.27015);
	ft_complex(&tmp[1], 0.285, 0.01);
	ft_complex(&tmp[2], -0.8, 0.156);
	ft_complex(&tmp[3], 0.4, 0.4);
	ft_complex(&tmp[4], -0.4, 0.6);
	c = tmp[4];
	if (i == 'a')
		c = tmp[0];
	if (i == 'b')
		c = tmp[1];
	else if (i == 'c')
		c = tmp[2];
	else if (i == 'd')
		c = tmp[3];
	return (c);
}
