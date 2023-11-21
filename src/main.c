/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:13:16 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/21 11:24:17 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_puts(const char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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

int	main(int argc, const char *argv[])
{
	t_fractal	fr;

	if (ft_args(&fr, argc, argv))
	{
		ft_puts("Please enter one of the lines below:");
		ft_puts("./fractol Mandelbrot OR Julia {1..4}");
		return (EXIT_FAILURE);
	}
	if (graphics_init(&fr))
		return (EXIT_FAILURE);
	mlx_loop_hook(fr.mlx, ft_artist, &fr);
	mlx_loop_hook(fr.mlx, ft_joystick, &fr);
	mlx_scroll_hook(fr.mlx, ft_zoom, &fr);
	mlx_loop(fr.mlx);
	mlx_terminate(fr.mlx);
	return (EXIT_SUCCESS);
}
