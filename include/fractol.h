/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:17:38 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/24 17:57:05 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define TRUE 1
# define FALSE 0
# define SIZE 720
# define STEP 36
# define ITER_MAX 100
# define MARGIN 0.03

typedef struct s_pixel
{
	int32_t		w;
	int32_t		h;
	uint32_t	color;
}	t_pixel;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_channel
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
}	t_channel;

typedef struct s_sierpinsky
{
	t_point	a;
	t_point	b;
	t_point	c;
}	t_sierpinsky;

/**
 * @brief A structure to store the characteristics of the fractal
 * 
 * @param f The function which calculates if a point belongs to the set or not
 * @param iter_max The maximum number of iterations
 * @param axis_len The length of the axis in z-plane
 * @param a The zoom factor
 * @param b The z-plane point related to canvas upper-left corner (0,0)
 * @param c The x-y coordinates in z-plane of the constant c for Julia sets
 * @param rgb The three color channels
 * @param x Combinat
 * @param j The Julia constant selector
 * @param mlx A pointer to the window instance
 * @param canvas A pointer to the canvas instance
 * @param pinsky A Sierpinsky object 
 */
typedef struct s_fractal
{
	const char		*name;
	unsigned int	(*f)(struct s_fractal *fractal, t_complex *c);
	uint32_t		iter_max;
	double			axis_len;
	double			a;
	t_complex		b;
	t_complex		c;
	t_channel		ch;
	int				rgb[3];
	int				x;
	int				j;
	mlx_t			*mlx;
	mlx_image_t		*canvas;
	t_sierpinsky	pinsky;
	double			z;
}	t_fractal;

uint32_t	ft_mandelbrot(t_fractal *fractal, t_complex *c);
uint32_t	ft_julia(t_fractal *fractal, t_complex *z);
void		ft_sierpinsky(t_point abc[], int n, t_fractal *fr);
int			mandelbrot_init(t_fractal *fractal, const char *name);
int			julia_init(t_fractal *fractal, const char *name);
int			sierpinsky_init(t_fractal *fractal, const char *name);
int			ft_args(t_fractal *fractal, int argc, const char *argv[]);
int			graphics_init(t_fractal *fractal);
/**
* @brief Transforms the current pixel position into a point on the z-plane.
* The linear transformation uses the line equation form of y = a * x + b.
* The y-axis is inverted to match the z-plane's orientation.
* @param z The complex variable which receives the transformed coordinates
* @param fractal The fractal instance
* @param pixel The current pixel
*/
void		ztrans(t_complex *z, t_fractal *fractal, t_pixel *pixel);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		ft_zoom(double xdelta, double ydelta, void *param);
void		ft_joystick(void *param);
int32_t		ft_bernstein_poly(double t, int *rgb);
void		ft_complex(t_complex *z, double x, double y);
void		ft_puts(const char *str);
void		ft_croupier(t_fractal *fr);
t_point		ft_middle(t_point a, t_point b);
void		ft_classic_artist(void *param);
void		ft_abc(t_fractal *fr);
void		ft_abc_zoom(double xdelta, double ydelta, void *param);
int			ft_pt_validation(t_point a);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_draw_triangle(t_fractal *fr, t_point a, t_point b, t_point c);
t_complex	ft_julia_set_c(char i);
void		ft_bresenham(t_point a, t_point b, t_fractal *fractal);

#endif