/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:17:46 by josfelip          #+#    #+#             */
/*   Updated: 2023/10/26 20:29:11 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

void	ft_zoom(double xdelta, double ydelta, void* param)
{
	t_fractal	*fractal;
	int32_t		x;
	int32_t		y;
	t_complex	c;
	
	fractal = param;
	mlx_get_mouse_pos(fractal->mlx, &x, &y);
	ztrans(&c, fractal, x, y);
	if (ydelta > 0)
	{
		fractal->x_zoom *= 1.1;
		fractal->y_zoom *= 1.1;
	}
	else if (ydelta < 0)
	{
		fractal->x_zoom *= 0.9;
		fractal->y_zoom *= 0.9;
	}
	printf("x: %d, y: %d, z: %f\n", x, y, fractal->y_zoom);
}

void	ft_joystick(void *param)
{	
	t_fractal	*fractal;
	
	fractal = param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
		fractal->imax += STEP / fractal->y_zoom;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		fractal->imax -= STEP / fractal->y_zoom;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		fractal->rmin -= STEP / fractal->x_zoom;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
		fractal->rmin += STEP / fractal->x_zoom;
}