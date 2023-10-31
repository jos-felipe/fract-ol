/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:17:59 by josfelip          #+#    #+#             */
/*   Updated: 2023/10/30 23:01:19 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

/**
* @brief Transforms the current pixel position into a point on the z domain
* @param c The complex number which receives the transformed coordinates
* @param fractal The fractal instance
* @param w The current pixel's width
* @param h The current pixel's height
*/
void	ztrans(t_complex *c, t_fractal *fractal, uint32_t w, uint32_t h)
{
	c->x = (+1.0) * fractal->a * w + fractal->b.x;
	c->y = (-1.0) * fractal->a * h + fractal->b.y;
}

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	ft_bernstein_poly(uint32_t i, uint32_t iter_max)
{
	double		t;
	int32_t		color;

	t = 1.0 * i / iter_max;
	color = ft_pixel(
						255 * 15 * (1 - t) * (1 - t) * t * t,
						255 * 9 * (1 - t) * t * t * t,
						255 * 8.5 * (1 - t) * (1 - t) * (1 - t) * t,
						255);
	return (color);
}