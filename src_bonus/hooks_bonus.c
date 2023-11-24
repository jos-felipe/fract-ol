/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:17:46 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/24 13:58:54 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	ft_zoom(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	t_pixel		pixel;
	t_complex	cursor;
	t_complex	d;

	xdelta = 0;
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

void	ft_scroll_in(t_fractal *fr, int32_t width, int32_t height)
{
	fr->pinsky.a.x -= (width - fr->pinsky.a.x) / 10;
	fr->pinsky.a.y -= (height - fr->pinsky.a.y) / 10;
	fr->pinsky.b.x -= (width - fr->pinsky.b.x) / 10;
	fr->pinsky.b.y -= (height - fr->pinsky.b.y) / 10;
	fr->pinsky.c.x -= (width - fr->pinsky.c.x) / 10;
	fr->pinsky.c.y -= (height - fr->pinsky.c.y) / 10;
	ft_mlx_update(fr);
}

void	ft_scroll_out(t_fractal *fr, int32_t width, int32_t height)
{
	fr->pinsky.a.x += (width - fr->pinsky.a.x) / 10;
	fr->pinsky.a.y += (height - fr->pinsky.a.y) / 10;
	fr->pinsky.b.x += (width - fr->pinsky.b.x) / 10;
	fr->pinsky.b.y += (height - fr->pinsky.b.y) / 10;
	fr->pinsky.c.x += (width - fr->pinsky.c.x) / 10;
	fr->pinsky.c.y += (height - fr->pinsky.c.y) / 10;
	ft_mlx_update(fr);
}

void	ft_abc_zoom(double xdelta, double ydelta, void *param)
{
	t_fractal	*fr;
	int32_t		width;
	int32_t		height;

	xdelta = 0;
	fr = param;
	mlx_get_mouse_pos(fr->mlx, &width, &height);
	if (ydelta > 0)
		ft_scroll_in(fr, width, height);
	else if (ydelta < 0)
		ft_scroll_out(fr, width, height);
}

void	ft_joystick(void *param)
{	
	t_fractal	*fractal;

	fractal = param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_SPACE))
		ft_croupier(fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_F1))
		fractal->c = ft_julia_set_c('a');
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_F2))
		fractal->c = ft_julia_set_c('b');
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_F3))
		fractal->c = ft_julia_set_c('c');
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_F4))
		fractal->c = ft_julia_set_c('d');
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
		fractal->b.y += fractal->a * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		fractal->b.y -= fractal->a * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		fractal->b.x -= fractal->a * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
		fractal->b.x += fractal->a * STEP;
}
