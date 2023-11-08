/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:05:39 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/08 17:47:39 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mandelbrot_init(t_fractal *fractal)
{	
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

int	julia_init(t_fractal *fractal)
{	
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
				status = mandelbrot_init(fractal);
			else if (!ft_strncmp(argv[1], "Julia", 5))
			{
				status = julia_init(fractal);
				if (argc > 2)
					julia_sets(&fractal->c, ft_atoi(argv[2]) - 1);
			}	
			else if (!ft_strncmp(argv[1], "burningship", 11))
				status = EXIT_SUCCESS;
		}
	return (status);
}

int	graphics_init(t_fractal *fractal, mlx_t	*mlx, mlx_image_t *canvas)
{
	mlx = mlx_init(SIZE, SIZE, "fract-ol", false);
	if (!mlx)
	{
		ft_putstr_fd(mlx_strerror(mlx_errno), 1);
		return(EXIT_FAILURE);
	}
	canvas = mlx_new_image(mlx, SIZE, SIZE);
	if (!canvas)
	{
		mlx_close_window(mlx);
		ft_putstr_fd(mlx_strerror(mlx_errno), 1);
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, canvas, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		ft_putstr_fd(mlx_strerror(mlx_errno), 1);
		return(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}