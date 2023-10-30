/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:13:16 by josfelip          #+#    #+#             */
/*   Updated: 2023/10/30 17:30:32 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../include/fractol.h"


void ft_artist(void* param)
{
	t_fractal	*fractal;
	uint32_t	w;
	uint32_t	h;
	uint32_t	color;
	t_complex	c;
	
	fractal = param;
	w = 0;
	while (w < fractal->canvas->width)
	{
		h = 0;
		while (h < fractal->canvas->height)
		{
			ztrans(&c, fractal, w, h);
			color = fractal->f(fractal, &c);
			mlx_put_pixel(fractal->canvas, w, h, color);
			h++;
		}
		w++;
	}
}

int32_t main(int32_t argc, const char* argv[])
{
	mlx_t		*mlx;
	mlx_image_t	*canvas;
	t_fractal	fractal;

	if (argc > 1)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 10))
			mandelbrot_init(&fractal);
		else if (!ft_strncmp(argv[1], "julia", 5))
			fractal.f = ft_mandelbrot;
		else if (!ft_strncmp(argv[1], "burningship", 11))
			fractal.f = ft_mandelbrot;
		else
		{
			ft_putstr_fd("Usage: ./fractol [fractal]\n", 1);
			return (EXIT_FAILURE);
		}
		mlx = mlx_init(SIZE, SIZE, fractal.name, false);
		if (!mlx)
		{
			puts(mlx_strerror(mlx_errno));
			return(EXIT_FAILURE);
		}
		canvas = mlx_new_image(mlx, SIZE, SIZE);
		if (!canvas)
		{
			mlx_close_window(mlx);
			puts(mlx_strerror(mlx_errno));
			return(EXIT_FAILURE);
		}
		if (mlx_image_to_window(mlx, canvas, 0, 0) == -1)
		{
			mlx_close_window(mlx);
			puts(mlx_strerror(mlx_errno));
			return(EXIT_FAILURE);
		}
		fractal.mlx = mlx;
		fractal.canvas = canvas;
		mlx_loop_hook(mlx, ft_artist, &fractal);
		mlx_loop_hook(mlx, ft_joystick, &fractal);
		mlx_scroll_hook(mlx, ft_zoom, &fractal);
		
		mlx_loop(mlx);
		mlx_terminate(mlx);
		return (EXIT_SUCCESS);
	}
	else
	{
		puts("Usage: ./fractol [fractal]");
		return (EXIT_FAILURE);
	}
}