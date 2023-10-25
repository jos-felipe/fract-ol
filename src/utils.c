#include <stdlib.h>
#include "../include/fractol.h"

void	ztrans(t_complex *c, t_fractal *fractal, uint32_t width, uint32_t height)
{
	c->x = width / fractal->zoom + fractal->offset->x;
	c->y = height / fractal->zoom * (-1) + fractal->offset->y;
}

void mandelbrot_init(t_fractal *fractal, const char *name)
{	
	fractal->name = name;
	fractal->zoom = SIZE / 4.00;
	fractal->offset->x = -2.0;
	fractal->offset->y = +2.0;
	fractal->f = ft_mandelbrot;
	fractal->iter_max = 100;
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}