/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:17:46 by josfelip          #+#    #+#             */
/*   Updated: 2023/10/30 17:06:55 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

void	ft_zoom(double xdelta, double ydelta, void* param)
{
	t_fractal	*fractal;
	int32_t		w;
	int32_t		h;
	t_complex	c;
	
	fractal = param;
	mlx_get_mouse_pos(fractal->mlx, &w, &h);
	ztrans(&c, fractal, w, h);
	if (ydelta > 0)
	{
		fractal->rmin *= 0.95;
		fractal->rmax *= 0.95;
		fractal->imin *= 0.95;
		fractal->imax *= 0.95;
	}
	else if (ydelta < 0)
	{
		fractal->rmin *= 1.05;
		fractal->rmax *= 1.05;
		fractal->imin *= 1.05;
		fractal->imax *= 1.05;
	}
	fractal->x_zoom = (fractal->rmax - fractal->rmin) / fractal->canvas->width;
	fractal->y_zoom = (fractal->imax - fractal->imin) / fractal->canvas->width;
	printf("w: %d, h: %d, zoom: %f\n", w, h, 1 / fractal->x_zoom);
}

void	ft_joystick(void *param)
{	
	t_fractal	*fractal;
	
	fractal = param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
		fractal->imax -= fractal->y_zoom * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		fractal->imax += fractal->y_zoom * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		fractal->rmin += fractal->x_zoom * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
		fractal->rmin -= fractal->x_zoom * STEP;
}