/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:17:59 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/24 17:33:10 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ztrans(t_complex *z, t_fractal *fractal, t_pixel *pixel)
{
	z->x = (+1.0) * fractal->a * pixel->w + fractal->b.x;
	z->y = (-1.0) * fractal->a * pixel->h + fractal->b.y;
}

int32_t	ft_bernstein_poly(double t, int *rgb)
{
	int32_t	poly[3];

	poly[rgb[0]] = 255 * 15 * (1 - t) * (1 - t) * t * t;
	poly[rgb[1]] = 255 * 9 * (1 - t) * t * t * t;
	poly[rgb[2]] = 255 * 8.5 * (1 - t) * (1 - t) * (1 - t) * t;
	return (ft_pixel(poly[0], poly[1], poly[2], 255));
}

void	ft_complex(t_complex *z, double x, double y)
{
	z->x = x;
	z->y = y;
}

void	ft_croupier(t_fractal *fr)
{
	int	tmp;

	fr->x++;
	if (fr->x > 1)
		fr->x = 0;
	tmp = fr->rgb[fr->x];
	fr->rgb[fr->x] = fr->rgb[fr->x + 1];
	fr->rgb[fr->x + 1] = tmp;
}
