/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:38:05 by josfelip          #+#    #+#             */
/*   Updated: 2023/10/30 16:57:24 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Mathmathical representation of fractal sets

#include "../include/fractol.h"

uint32_t ft_mandelbrot(t_fractal *fractal, t_complex *c)
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
		color = ft_bernstein_poly(i, fractal->iter_max);
	return (color);
}