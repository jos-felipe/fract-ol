/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:13:16 by josfelip          #+#    #+#             */
/*   Updated: 2023/10/25 14:15:59 by josfelip         ###   ########.fr       */
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
	uint32_t	width;
	uint32_t	height;
	uint32_t	color;
	
	fractal = param;
	width = 0;
	while (width < fractal->canvas->width)
	{
		height = 0;
		while (height < fractal->canvas->height)
		{
			color = fractal->f(fractal, width, height);
			mlx_put_pixel(fractal->canvas, width, height, color);
			height++;
		}
		width++;
	}
}

uint32_t ft_mandelbrot(t_fractal *fractal, uint32_t width, uint32_t height)
{
	double		xtemp;
	t_complex	z;
	t_complex	c;
	uint32_t 	color;
	int32_t		i;
	
	z.x = 0;
	z.y = 0;
	ztrans(&c, fractal, width, height);
	i = 0;
	while (i < fractal->iter_max)
	{
		xtemp = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = xtemp;
		if (z.x * z.x + z.y * z.y > 4)
			break ;
		i++;
	}
	if (i == fractal->iter_max)
		color = ft_pixel(0x00, 0x00, 0x00, 0xFF);
	else
		color = ft_pixel(0xFF, 0xFF, 0xFF, 0xFF);
	return (color);
}

void ft_joystick(void	*param)
{	
	t_fractal		*fractal;
	mlx_instance_t	*zero_ref;
	
	fractal = param;
	zero_ref = &fractal->canvas->instances[0];
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
		fractal->offset->y -= STEP / fractal->zoom;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		fractal->offset->y += STEP / fractal->zoom;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		fractal->offset->x += STEP / fractal->zoom;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
		fractal->offset->x -= STEP / fractal->zoom;
}

// -----------------------------------------------------------------------------

int32_t main(int32_t argc, const char* argv[])
{
	mlx_t		*mlx;
	mlx_image_t	*canvas;
	t_fractal	fractal;

	if (argc > 1)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 10))
			mandelbrot_init(&fractal, argv[1]);
		else if (!ft_strncmp(argv[1], "julia", 5))
			fractal.f = ft_mandelbrot;
		else if (!ft_strncmp(argv[1], "burningship", 11))
			fractal.f = ft_mandelbrot;
		else
		{
			puts("Usage: ./fractol [fractal]");
			return (EXIT_FAILURE);
		}
		mlx = mlx_init(SIZE, SIZE, fractal.name, true);
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