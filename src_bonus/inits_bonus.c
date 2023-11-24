/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:05:39 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/24 10:59:12 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

int	mandelbrot_init(t_fractal *fractal, const char *name)
{
	fractal->name = name;
	fractal->f = ft_mandelbrot;
	fractal->iter_max = ITER_MAX;
	fractal->axis_len = 4.0;
	fractal->a = fractal->axis_len / SIZE;
	fractal->b.x = 0.0 - fractal->axis_len / 2.0;
	fractal->b.y = 0.0 + fractal->axis_len / 2.0;
	fractal->rgb[0] = 0;
	fractal->rgb[1] = 1;
	fractal->rgb[2] = 2;
	fractal->x = 0;
	return (EXIT_SUCCESS);
}

int	julia_init(t_fractal *fractal, const char *name)
{	
	fractal->name = name;
	fractal->f = ft_julia;
	fractal->iter_max = ITER_MAX;
	fractal->axis_len = 4.0;
	fractal->a = fractal->axis_len / SIZE;
	fractal->b.x = 0.0 - fractal->axis_len / 2.0;
	fractal->b.y = 0.0 + fractal->axis_len / 2.0;
	fractal->rgb[0] = 0;
	fractal->rgb[1] = 1;
	fractal->rgb[2] = 2;
	fractal->x = 0;
	fractal->c = ft_julia_set_c('0');
	return (EXIT_SUCCESS);
}

int	sierpinsky_init(t_fractal *fractal, const char *name)
{	
	fractal->name = name;
	fractal->iter_max = 9;
	fractal->z = 1;
	fractal->x = 0;
	ft_abc(fractal);
	return (EXIT_SUCCESS);
}

int	ft_args(t_fractal *fractal, int argc, const char *argv[])
{
	int	status;

	status = EXIT_FAILURE;
	if (argc > 1)
	{
		if (!ft_strcmp(argv[1], "Mandelbrot"))
			status = mandelbrot_init(fractal, argv[1]);
		else if (!ft_strcmp(argv[1], "Julia"))
		{
			status = julia_init(fractal, argv[1]);
			if (argc > 2)
				fractal->c = ft_julia_set_c(argv[2][0]);
		}	
		else if (!ft_strcmp(argv[1], "Sierpinsky"))
			status = sierpinsky_init(fractal, argv[1]);
	}
	return (status);
}

int	graphics_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init(SIZE, SIZE, fractal->name, FALSE);
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
