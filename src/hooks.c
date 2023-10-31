/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:17:46 by josfelip          #+#    #+#             */
/*   Updated: 2023/10/31 11:42:49 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

void	ft_zoom(double xdelta, double ydelta, void* param)
{
	t_fractal	*fractal;
	int32_t		w;
	int32_t		h;
	t_complex	pointer;
	t_complex	d;
	
	fractal = param;
	mlx_get_mouse_pos(fractal->mlx, &w, &h);
	ztrans(&pointer, fractal, w, h);
	d.x = pointer.x - fractal->b.x;
	d.y = fractal->b.y - pointer.y;
	if (ydelta > 0)
		fractal->axis_len *= 0.90;
	else if (ydelta < 0)
		fractal->axis_len *= 1.10;
	fractal->a = fractal->axis_len / SIZE;
	fractal->b.x += d.x / 10;
	fractal->b.y -= d.y / 10;
	printf("w: %d, h: %d, zoom: %f\n", w, h, 1 / fractal->a);
}

void	ft_joystick(void *param)
{	
	t_fractal	*fractal;
	
	fractal = param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_R))
		mandelbrot_init(fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
		fractal->b.y -= fractal->a * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		fractal->b.y += fractal->a * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		fractal->b.x += fractal->a * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
		fractal->b.x -= fractal->a * STEP;
}