/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:13:16 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/10 17:51:56 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
 
#include <stdbool.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../include/fractol.h"

void	ft_puts(const char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_artist(void *param)
{
	t_fractal	*fractal;
	t_pixel		pixel;
	t_complex	z;

	fractal = param;
	pixel.h = 0;
	while (pixel.h < SIZE)
	{
		pixel.w = 0;
		while (pixel.w < SIZE)
		{
			ztrans(&z, fractal, &pixel);
			pixel.color = fractal->f(fractal, &z);
			mlx_put_pixel(fractal->canvas, pixel.w, pixel.h, pixel.color);
			pixel.w++;
		}
		pixel.h++;
	}
}

int32_t	main(int32_t argc, const char *argv[])
{
	t_fractal	fractal;

	if (ft_args(&fractal, argc, argv))
	{
		ft_puts("Usage: ./fractol [ Mandelbrot|Julia ] {1..4}");
		return (EXIT_FAILURE);
	}
	if (graphics_init(&fractal))
		return (EXIT_FAILURE);
	mlx_loop_hook(fractal.mlx, ft_artist, &fractal);
	mlx_loop_hook(fractal.mlx, ft_joystick, &fractal);
	mlx_scroll_hook(fractal.mlx, ft_zoom, &fractal);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}
