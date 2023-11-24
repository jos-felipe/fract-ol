/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_pinsky_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:17:46 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/24 15:27:04 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../include/fractol_bonus.h"

void	ft_mlx_update(t_fractal *fr)
{
	mlx_delete_image(fr->mlx, fr->canvas);
	fr->canvas = mlx_new_image(fr->mlx, SIZE, SIZE);
	mlx_image_to_window(fr->mlx, fr->canvas, 0, 0);
}

void	ft_mlx_key(t_sierpinsky *pinsky, int x_move, int y_move, t_fractal *fr)

{
	pinsky->a.x += x_move;
	pinsky->b.x += x_move;
	pinsky->c.x += x_move;
	pinsky->a.y += y_move;
	pinsky->b.y += y_move;
	pinsky->c.y += y_move;
	ft_mlx_update(fr);
}

void	ft_joystick_pinsky(void *param)
{	
	t_fractal	*fractal;

	fractal = param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_F1))
		fractal->x = 1;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_F2))
		fractal->x = 2;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_F3))
		fractal->x = 3;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_F4))
		fractal->x = 4;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_F5))
		fractal->x = 0;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
		ft_mlx_key(&fractal->pinsky, 0, -STEP, fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		ft_mlx_key(&fractal->pinsky, 0, +STEP, fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		ft_mlx_key(&fractal->pinsky, -STEP, 0, fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
		ft_mlx_key(&fractal->pinsky, +STEP, 0, fractal);
}

void	ft_colorize(t_fractal *fr, t_point a, double t)
{
	int32_t	color;

	if (fr->x == 1)
		t = (double)(a.x * a.y) / (SIZE * SIZE);
	else if (fr->x == 2)
		t = (double)(a.x + a.y) / (SIZE * 2);
	else if (fr->x == 3)
		t *= t;
	else if (fr->x == 4)
		t = sqrt(t);
	color = ft_bernstein_poly(t, fr->rgb);
	if (!ft_pt_validation(a))
		mlx_put_pixel(fr->canvas, a.x, a.y, color);
}
