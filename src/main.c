/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:13:16 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/07 18:23:42 by josfelip         ###   ########.fr       */
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
	t_pixel		pixel;
	t_complex	z;
	
	fractal = param;
	pixel.h = 0;
	while (pixel.h < SIZE)
	{
		pixel.w = 0;
		while (pixel.w < SIZE)
		{
			ztrans(fractal, &pixel, &z);
			pixel.color = fractal->f(fractal, &z);
			mlx_put_pixel(fractal->canvas, pixel.w, pixel.h, pixel.color);
			pixel.w++;
		}
		pixel.h++;
	}
}

int32_t main(int32_t argc, const char* argv[])
{
	t_fractal	fractal;
	mlx_t		*mlx;
	mlx_image_t	*canvas;

	if (argc > 1)
	{
		if (!ft_strncmp(argv[1], "Mandelbrot", 10))
			mandelbrot_init(&fractal);
		else if (!ft_strncmp(argv[1], "Julia", 5))
		{
			julia_init(&fractal);
			if (argc > 2)
				julia_multiset(&fractal.c, ft_atoi(argv[2]) - 1);
		}	
		else if (!ft_strncmp(argv[1], "burningship", 11))
			return ;
		else
		{
			ft_putstr_fd("Usage: ./fractol [fractal]\n", 1);
			return (EXIT_FAILURE);
		}
		mlx = mlx_init(SIZE, SIZE, argv[1], false);
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
		fractal.mlx(fractal, mlx, canvas);
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