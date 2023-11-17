/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:38:05 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/17 17:23:09 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Mathematical models for fractal sets

#include "../include/fractol_bonus.h"

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

void	ft_sierpinsky(t_point a, t_point b, t_point c, int n, t_fractal *fractal)
{
	if(n > 0)
	{
		ft_bresenham(a, b, fractal);
		ft_bresenham(b, c, fractal);
		ft_bresenham(c, a, fractal);
		ft_sierpinsky(a, ft_middle(a, b), ft_middle(a, c), n-1, fractal);
		ft_sierpinsky(ft_middle(a, b), b, ft_middle(b, c), n-1, fractal);
		ft_sierpinsky(ft_middle(a, c), ft_middle(b, c), c, n-1, fractal);
	}
	return ;
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
