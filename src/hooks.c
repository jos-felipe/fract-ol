/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:17:46 by josfelip          #+#    #+#             */
/*   Updated: 2023/10/30 23:43:25 by josfelip         ###   ########.fr       */
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
	
	fractal = param;
	mlx_get_mouse_pos(fractal->mlx, &w, &h);
	ztrans(&pointer, fractal, w, h);
	if (ydelta > 0)
		fractal->axis_len *= 0.90;
	else if (ydelta < 0)
		fractal->axis_len *= 1.10;
	fractal->a = fractal->axis_len / SIZE;
	fractal->b.x = pointer.x - fractal->axis_len / 2.0;
	fractal->b.y = pointer.y + fractal->axis_len / 2.0;
	printf("w: %d, h: %d, zoom: %f\n", w, h, 1 / fractal->a);
}

void	ft_joystick(void *param)
{	
	t_fractal	*fractal;
	
	fractal = param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
		fractal->b.y += fractal->a * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		fractal->b.y -= fractal->a * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		fractal->b.x -= fractal->a * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
		fractal->b.x += fractal->a * STEP;
}