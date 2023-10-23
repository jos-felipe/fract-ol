/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:13:16 by josfelip          #+#    #+#             */
/*   Updated: 2023/10/23 14:51:13 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../include/fractol.h"

#define WIDTH 512
#define HEIGHT 512
#define SIZE 720
#define AXIS_LEN 3
#define MAX_ITER 100

static mlx_image_t* image;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	for (int32_t i = 0; i < image->width; ++i)
	{
		for (int32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void ft_zmap(void* param)
{
	double		zoom;
	t_complex	*c;

	zoom = (double)AXIS_LEN / SIZE;
	for (int32_t i = 0; i < image->width; ++i)
	{
		for (int32_t j = 0; j < image->height; ++j)
		{
			c = complex_init(zoom * i, zoom * j);
			uint32_t color = ft_mandelbrot(&c);
			// uint32_t color = ft_pixel(
			// 	rand() % 0xFF, // R
			// 	rand() % 0xFF, // G
			// 	rand() % 0xFF, // B
			// 	rand() % 0xFF  // A
			// );
			mlx_put_pixel(image, i, j, color);
		}
	}
}

uint32_t ft_mandelbrot(t_complex *c)
{
	double		xtemp;
	t_complex	*z;
	uint32_t 	color;
	int32_t		i;
	
	z = complex_init(0, 0);
	i = 0;
	while (i < MAX_ITER)
	{
		xtemp = z->x * z->x - z->y * z->y + c->x;
		z->y = 2 * z->x * z->y + c->y;
		z->x = xtemp;
		if (z->x * z->x + z->y * z->y > 4)
			break ;
		i++;
	}
	if (i == MAX_ITER)
		color = ft_pixel(0, 0, 0, 0);
	else
		color = ft_pixel(0, 0, 0, 0xFF);
	return (color);
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

int32_t main(int32_t argc, const char* argv[])
{
	mlx_t	*mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(SIZE, SIZE, "fract-ol", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, SIZE, SIZE)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}