/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:17:38 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/07 18:21:22 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/libft.h"

#define SIZE 720
#define STEP 100

typedef struct s_pixel
{
	int32_t w;
	int32_t h;
	uint32_t color;
}	t_pixel;

typedef struct s_complex
{
	double x;
	double y;
}	t_complex;

typedef struct s_channel
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
}	t_channel;

/**
 * @brief A structure to store the characteristics of the fractal
 * 
 * @param name The fractal's name
 * @param f The function which identify if a point belongs to the set or not
 * @param iter_max The maximum number of iterations
 * @param axis_len The length of the axis in z-plane
 * @param a The zoom factor
 * @param b The x-y coordinates in z-plane of canvas upper-left corner (0,0)
 * @param c The x-y coordinates in z-plane of the constant c in Julia set
 * @param k The color index
 * @param mlx A pointer to the window instance
 * @param canvas A pointer to the canvas instance
 */ 
typedef struct s_fractal
{
	uint32_t	(*f)(struct s_fractal *fractal, t_complex *c);
	uint32_t	iter_max;
	double		axis_len;
	double		a;
	t_complex	b;
	t_complex	c;
	t_channel	ch;
	mlx_t 		*mlx;
	mlx_image_t	*canvas;
}	t_fractal;

uint32_t	ft_mandelbrot(t_fractal *fractal, t_complex *c);
uint32_t	ft_julia(t_fractal *fractal, t_complex *z);
void		mandelbrot_init(t_fractal *fractal);
void		julia_init(t_fractal *fractal);
void		julia_multiset(t_complex *c, int i);
void		ztrans(t_fractal *fractal, t_pixel *pixel, t_complex *z);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		ft_zoom(double xdelta, double ydelta, void* param);
void		ft_joystick(void *param);
int32_t		ft_bernstein_poly(uint32_t i, t_fractal *fractal);
void		ft_shift(t_channel *ch);
void		ft_complex(t_complex *z, double x, double y);

# endif