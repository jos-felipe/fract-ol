# ifndef FRACTOL_H
# define FRACTOL_H

typedef struct s_complex
{
	double x;
	double y;
} t_complex;

t_complex	*complex_init(double x, double y);

# endif