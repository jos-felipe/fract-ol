#include <stdlib.h>
#include "../include/fractol.h"

t_complex 	*complex_init(double x, double y)
{
	t_complex *c;

	c = malloc(sizeof(t_complex));
	c->x = x;
	c->y = y;
	return (c);
}

void	ztrans(t_fractal *fractal, uint32_t width, uint32_t height)
{
	fractal->c->x = width / fractal->zoom + fractal->offset->x;
	fractal->c->y = height / fractal->zoom * (-1) + fractal->offset->y;
}

void mandelbrot_init(t_fractal *fractal)
{	
	fractal->name = ft_strdup("Mandelbrot");
	fractal->zoom = SIZE / 4.00;
	fractal->offset = complex_init(-2.0, +2.0);
	fractal->f = ft_mandelbrot;
}