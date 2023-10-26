/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:17:38 by josfelip          #+#    #+#             */
/*   Updated: 2023/10/26 20:42:08 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/libft.h"

#define SIZE 720
#define STEP 100

typedef struct s_complex
{
	double x;
	double y;
}	t_complex;

/**
 * @brief A structure to store the characteristics of the fractal
 * 
 * @param mlx A pointer to the window instance
 * @param canvas A pointer to the canvas instance
 * @param zoom The zoom factor
 * @param offset The position on complex plane corresponding to the canvas upper-left corner 
 * @param f The function address which performs the color calculation
 * @param name The fractal's name
 * @param iter_max The maximum number of iterations
 */ 
typedef struct s_fractal
{
	const char	*name;
	mlx_t		*mlx;
	mlx_image_t	*canvas;
	uint32_t	(*f)(struct s_fractal *fractal, uint32_t width, uint32_t height);
	uint32_t	iter_max;
	double		x_zoom;
	double		y_zoom;
	double		rmax;
	double		rmin;
	double		imax;
	double		imin;
}	t_fractal;

uint32_t	ft_mandelbrot(t_fractal *fractal, uint32_t width, uint32_t height);

void		mandelbrot_init(t_fractal *fractal, const char *name);

/// @brief Transforms the current pixel position into a point on the complex domain
void		ztrans(t_complex *c, t_fractal *fractal, uint32_t width, uint32_t height);

int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

void		ft_zoom(double xdelta, double ydelta, void* param);

void		ft_joystick(void *param);

int32_t		ft_bernstein_poly(uint32_t i, uint32_t iter_max);

# endif