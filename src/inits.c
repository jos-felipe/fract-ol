/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:05:39 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/10 18:07:43 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mandelbrot_init(t_fractal *fractal, const char *name)
{	
	fractal->name = name;
	fractal->f = ft_mandelbrot;
	fractal->iter_max = 100;
	fractal->axis_len = 4.0;
	fractal->a = fractal->axis_len / SIZE;
	fractal->b.x = 0.0 - fractal->axis_len / 2.0;
	fractal->b.y = 0.0 + fractal->axis_len / 2.0;
	fractal->ch.r = 0;
	fractal->ch.g = 1;
	fractal->ch.b = 2;
	return (EXIT_SUCCESS);
}

int	julia_init(t_fractal *fractal, const char *name)
{	
	fractal->name = ft_strdup(name);
	fractal->f = ft_julia;
	fractal->iter_max = 100;
	fractal->axis_len = 4.0;
	fractal->a = fractal->axis_len / SIZE;
	fractal->b.x = 0.0 - fractal->axis_len / 2.0;
	fractal->b.y = 0.0 + fractal->axis_len / 2.0;
	fractal->ch.r = 0;
	fractal->ch.g = 1;
	fractal->ch.b = 2;
	fractal->j = 0;
	julia_sets(&fractal->c, fractal->j);
	return (EXIT_SUCCESS);
}

int	ft_args(t_fractal *fractal, int argc, const char *argv[])
{
	int	status;

	status = EXIT_FAILURE;
	if (argc > 1)
	{
		if (!ft_strncmp(argv[1], "Mandelbrot", 10))
			status = mandelbrot_init(fractal, argv[1]);
		else if (!ft_strncmp(argv[1], "Julia", 5))
		{
			status = julia_init(fractal, argv[1]);
			if (argc > 2)
				julia_sets(&fractal->c, ft_atoi(argv[2]) - 1);
		}	
		else if (!ft_strncmp(argv[1], "burningship", 11))
			status = EXIT_SUCCESS;
	}
	return (status);
}

int	graphics_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init(SIZE, SIZE, fractal->name, false);
	if (!fractal->mlx)
	{
		ft_puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	fractal->canvas = mlx_new_image(fractal->mlx, SIZE, SIZE);
	if (!fractal->canvas)
	{
		mlx_close_window(fractal->mlx);
		ft_puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(fractal->mlx, fractal->canvas, 0, 0) == -1)
	{
		mlx_close_window(fractal->mlx);
		ft_puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
