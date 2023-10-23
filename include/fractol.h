# ifndef FRACTOL_H
# define FRACTOL_H

#include "../lib/MLX42/include/MLX42/MLX42.h"

typedef struct s_complex
{
	double x;
	double y;
} t_complex;

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*paper;
} t_fractal;

t_complex	*complex_init(double x, double y);
uint32_t	ft_mandelbrot(t_complex *c);

# endif