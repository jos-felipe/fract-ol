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
	fractal->iter_max = 50;
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_zoom(double xdelta, double ydelta, void* param)
{
	t_fractal	*fractal;
	double		zoom_temp;
	
	fractal = param;
	zoom_temp = fractal->zoom;
	if (ydelta > 0)
		fractal->zoom *= 1.1;
	else if (ydelta < 0)
		fractal->zoom *= 0.9;
	fractal->offset->x *= zoom_temp / fractal->zoom;
	fractal->offset->y *= zoom_temp / fractal->zoom;
}

void	ft_joystick(void *param)
{	
	t_fractal	*fractal;
	
	fractal = param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
		fractal->offset->y += STEP / fractal->zoom;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		fractal->offset->y -= STEP / fractal->zoom;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		fractal->offset->x -= STEP / fractal->zoom;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
		fractal->offset->x += STEP / fractal->zoom;
}