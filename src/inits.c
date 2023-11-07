/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:05:39 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/07 18:20:42 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Functions to initialize the fractal structure

#include "../include/fractol.h"

void	mandelbrot_init(t_fractal *fractal)
{	
	fractal->f = ft_mandelbrot;
	fractal->iter_max = 100;
	fractal->axis_len = 4.0;
	fractal->a = fractal->axis_len / SIZE;
	fractal->b.x = 0.0 - fractal->axis_len / 2.0;
	fractal->b.y = 0.0 + fractal->axis_len / 2.0;
	fractal->ch.r = 0;
	fractal->ch.g = 1;
	fractal->ch.b = 2;
}

void	julia_init(t_fractal *fractal)
{	
	fractal->f = ft_julia;
	fractal->iter_max = 100;
	fractal->axis_len = 4.0;
	fractal->a = fractal->axis_len / SIZE;
	fractal->b.x = 0.0 - fractal->axis_len / 2.0;
	fractal->b.y = 0.0 + fractal->axis_len / 2.0;
	fractal->c.x = -0.7;
	fractal->c.y = 0.27015;
	fractal->ch.r = 0;
	fractal->ch.g = 1;
	fractal->ch.b = 2;
}

void	julia_multiset(t_complex *c, int i)
{
	t_complex	tmp[3];

	ft_complex(&tmp[0], 0.285, 0.01);
	ft_complex(&tmp[1], -0.8, 0.156);
	ft_complex(&tmp[2], 0.4, 0.4);
	if (i < 0 || i > 2)
		return ;
	c = &tmp[i];
}