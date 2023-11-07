/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:05:39 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/02 15:23:13 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Functions to initialize the fractal structure

#include "../include/fractol.h"

void	mandelbrot_init(t_fractal *fractal, mlx_t *mlx, mlx_image_t	*canvas)
{	
	fractal->name = "mandelbrot";
	fractal->f = ft_mandelbrot;
	fractal->iter_max = 100;
	fractal->axis_len = 4.0;
	fractal->a = fractal->axis_len / SIZE;
	fractal->b.x = 0.0 - fractal->axis_len / 2.0;
	fractal->b.y = 0.0 + fractal->axis_len / 2.0;
	fractal->ch.r = 0;
	fractal->ch.g = 1;
	fractal->ch.b = 2;
	fractal->mlx = mlx;
	fractal->canvas = canvas;
}

void	julia_init(t_fractal *fractal, mlx_t *mlx, mlx_image_t *canvas)
{	
	fractal->name = "julia";
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
	fractal->mlx = mlx;
	fractal->canvas = canvas;
}