# ifndef FRACTOL_H
# define FRACTOL_H

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/libft.h"

#define SIZE 720
#define STEP 5

typedef struct s_complex
{
	double x;
	double y;
} t_complex;

/**
 * @brief A fractal structure
 * 
 * @param mlx A pointer to the window
 * @param canvas A pointer to the canvas
 * @param zoom The zoom factor
 * @param offset The x-y coordinates of the upper-left corner of the canvas after zooming
 * @param f The function address which performs the color calculation
 * @param name The name of the fractal
 * @param iter_max The maximum number of iterations
 */ 
typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*canvas;
	double		zoom;
	t_complex	*offset;
	uint32_t	(*f)(t_fractal *fractal, uint32_t width, uint32_t height);
	char		*name;
	uint32_t	iter_max;
}	t_fractal;

uint32_t	ft_mandelbrot(t_fractal *fractal, uint32_t width, uint32_t height);

/// @brief Transforms the x-y coordinates of the current pixel to the x-y coordinates on the complex plane
void		ztrans(t_complex *c, t_fractal *fractal, uint32_t width, uint32_t height);

int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		mandelbrot_init(t_fractal *fractal, char *name);

# endif