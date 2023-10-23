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