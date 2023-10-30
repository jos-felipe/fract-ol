/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:05:39 by josfelip          #+#    #+#             */
/*   Updated: 2023/10/30 17:02:40 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Functions to initialize the fractal structure

#include "../include/fractol.h"

void	mandelbrot_init(t_fractal *fractal)
{	
	fractal->name = "mandelbrot";
	fractal->f = ft_mandelbrot;
	fractal->iter_max = 100;
	fractal->rmax = +2.0;
	fractal->rmin = -2.0;
	fractal->imax = +2.0;
	fractal->imin = -2.0;
	fractal->x_zoom = (fractal->rmax - fractal->rmin) / SIZE;
	fractal->y_zoom = (fractal->imax - fractal->imin) / SIZE;
}