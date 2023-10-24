# ifndef FRACTOL_H
# define FRACTOL_H

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/libft.h"

# define SIZE 720

typedef struct s_complex
{
	double x;
	double y;
} t_complex;

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*paper;
	double		zoom;
	t_complex	*offset;
	t_complex	*c;
	uint32_t (*f)(t_fractal *fractal);
	char		*name;
} t_fractal;

t_complex	*complex_init(double x, double y);
uint32_t	ft_mandelbrot(t_fractal *fractal);

# endif