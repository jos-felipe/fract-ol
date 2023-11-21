/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:17:46 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/20 21:52:34 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"
#include <string.h>

void	ft_zoom(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	t_pixel		pixel;
	t_complex	cursor;
	t_complex	d;

	// xdelta = 0;
	fractal = param;
	mlx_get_mouse_pos(fractal->mlx, &pixel.w, &pixel.h);
	ztrans(&cursor, fractal, &pixel);
	d.x = cursor.x - fractal->b.x;
	d.y = fractal->b.y - cursor.y;
	if (ydelta > 0)
	{
		fractal->axis_len *= 0.9;
		fractal->b.x += d.x / 10;
		fractal->b.y -= d.y / 10;
	}
	else if (ydelta < 0)
	{
		fractal->axis_len *= 1.1;
		fractal->b.x -= d.x / 10;
		fractal->b.y += d.y / 10;
	}
	fractal->a = fractal->axis_len / SIZE;
}

void	ft_abc_zoom(double xdelta, double ydelta, void *param)
{
	t_fractal	*fr;
	t_pixel		pixel;
	// t_point		d;

	fr = param;
	mlx_get_mouse_pos(fr->mlx, &pixel.w, &pixel.h);
	if (ydelta > 0)
	{
		// if (fr->z < 1)
		// 	fr->z = 1;
		// fr->z *= 1.1;
		fr->pinsky.a.x -= (pixel.w - fr->pinsky.a.x) / 10;
		fr->pinsky.a.y -= (pixel.h - fr->pinsky.a.y) / 10;
		fr->pinsky.b.x -= (pixel.w - fr->pinsky.b.x) / 10;
		fr->pinsky.b.y -= (pixel.h - fr->pinsky.b.y) / 10;
		fr->pinsky.c.x -= (pixel.w - fr->pinsky.c.x) / 10;
		fr->pinsky.c.y -= (pixel.h - fr->pinsky.c.y) / 10;
	}
	else if (ydelta < 0)
	{
		// if (fr->z > 1)
		// 	fr->z = 1;
		// fr->z *= 0.9;
		fr->pinsky.a.x += (pixel.w - fr->pinsky.a.x) / 10;
		fr->pinsky.a.y += (pixel.h - fr->pinsky.a.y) / 10;
		fr->pinsky.b.x += (pixel.w - fr->pinsky.b.x) / 10;
		fr->pinsky.b.y += (pixel.h - fr->pinsky.b.y) / 10;
		fr->pinsky.c.x += (pixel.w - fr->pinsky.c.x) / 10;
		fr->pinsky.c.y += (pixel.h - fr->pinsky.c.y) / 10;
	}
	mlx_delete_image(fr->mlx, fr->canvas);
	fr->canvas = mlx_new_image(fr->mlx, SIZE, SIZE);
	mlx_image_to_window(fr->mlx, fr->canvas, 0, 0);
}

void	ft_joystick(void *param)
{	
	t_fractal	*fractal;

	fractal = param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_SPACE))
		ft_croupier(fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_C))
		ft_julia_c(fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
		fractal->b.y += fractal->a * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		fractal->b.y -= fractal->a * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		fractal->b.x -= fractal->a * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
		fractal->b.x += fractal->a * STEP;
}

void	ft_julia_c(t_fractal *fractal)
{
	fractal->j++;
	if (fractal->j == 4)
		fractal->j = 0;
	julia_sets(&fractal->c, fractal->j);
}
