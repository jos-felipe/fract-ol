/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:17:59 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/07 17:15:17 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

/**
* @brief Transforms the current pixel position into a point on the z domain.
* The linear transformation uses the line equation form of y = a * x + b.
* The y-axis is inverted to match the z-plane's orientation.
* @param fractal The fractal instance
* @param pixel The current pixel
* @param z The complex variable which receives the transformed coordinates
*/
void		ztrans(t_fractal *fractal, t_pixel *pixel, t_complex *z)
{
	z->x = (+1.0) * fractal->a * pixel->w + fractal->b.x;
	z->y = (-1.0) * fractal->a * pixel->h + fractal->b.y;
}

int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t		ft_bernstein_poly(uint32_t i, t_fractal * fractal)
{
	double		t;
	int32_t		poly[3];
	t_channel	*ch;

	t = 1.0 * i / fractal->iter_max;
	ch = &fractal->ch;
	poly[0] = 255 * 15 * (1 - t) * (1 - t) * t * t;
	poly[1] = 255 * 9 * (1 - t) * t * t * t;
	poly[2] = 255 * 8.5 * (1 - t) * (1 - t) * (1 - t) * t;
	return (ft_pixel(poly[ch->r], poly[ch->g], poly[ch->b], 255));
}

void	ft_shift(t_channel *ch)
{
	int32_t	tmp;

	tmp = ch->r;
	ch->r = ch->g;
	ch->g = ch->b;
	ch->b = tmp;
}

void	ft_complex(t_complex *z, double x, double y)
{
	z->x = x;
	z->y = y;
}