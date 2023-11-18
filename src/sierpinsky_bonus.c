/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:45:17 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/17 21:04:00 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	ft_skytrans(t_complex *p, t_fractal *fr, t_pixel px)
{
	p->x = (+1.0) * fr->a * px.w + fr->b.x;
	p->y = (+1.0) * fr->a * px.h + fr->b.y;
}

void	ft_2pixel(t_point *a, t_point *b, t_fractal *fr)
{
	a->x -= fr->dx; 
	b->x += fr->dx;
	a->y -= fr->dx;
	b->y += fr->dx;
}
void	ft_bresenham(t_point a, t_point b, t_fractal *fractal)
{
	uint32_t color = ft_pixel(255, 255, 255, 255);

	int32_t    dis;

    int32_t    dx;
    int32_t    dy;
    int32_t i = 0;

	ft_2pixel(&a, &b, fractal);

    dx = b.x - a.x;
    dy = b.y - a.y;

    if (abs(dx) > abs(dy))
    {
        dis = (2 * abs(dy)) - abs(dx);
        while (i < abs(dx))
        {
            if (dx < 0)
                a.x = a.x - 1;
            else
                a.x = a.x + 1;
            if (dis < 0)
                dis = dis + 2*abs(dy);
            else
            {
                if (dy < 0)
                    a.y = a.y - 1;
                else
                    a.y = a.y + 1;
                dis = dis + 2*(abs(dy) - abs(dx));
            }
            i++;
			mlx_put_pixel(fractal->canvas, a.x, a.y, color);
        }
    }
    else
    {
        dis = (2 * abs(dx)) - abs(dy);
        while (i < abs(dy))
        {
            if (dy < 0)
                a.y = a.y - 1;
            else
                a.y = a.y + 1;
            if (dis < 0)
                dis = dis + 2*abs(dx);
            else
            {
                if (dx < 0)
                    a.x = a.x - 1;
                else 
                    a.x = a.x + 1;
                dis = dis + 2*(abs(dx) - abs(dy));
            }
            i++;
            mlx_put_pixel(fractal->canvas, a.x, a.y, color);
        }
        
    }
}

t_point ft_middle(t_point a, t_point b)
{
    t_point c;

    c.x = (a.x + b.x) / 2;
    c.y = (a.y + b.y) / 2;

    return (c);
}

t_point	ft_strans(t_point p, t_fractal *fr)
{
	t_point	res;
	
	res.x = fr->a * p.x + fr->b.x;
	res.y = fr->a * p.y + fr->b.y;
	return (res);
}

void	ft_strans_(t_point *p1, t_point *p2, t_fractal *fr)
{
	int	dx;
	int	dy;

	dx = fr->a * (p2->x - p1->x);
	dy = fr->a * (p2->y - p1->y);
	p1->x -= dx / 2;
	p1->y -= dy / 2;
	p2->x += dx / 2;
	p2->y += dy / 2;
}

void	ft_rev_strans(t_point *p2, t_point p1, t_fractal *fr)
{
	p2->x = (1 / fr->a) * p1.x - fr->b.x;
	p2->y = (1 / fr->a) * p1.y - fr->b.y;
}

void	ft_classic_artist(void *param)
{
	t_fractal	*fr;
	int			n;
	
	fr = param;
	n = fr->iter_max;
	ft_sierpinsky(fr->pinsky.a, fr->pinsky.b, fr->pinsky.c, n, fr);
}

void	ft_abc(t_fractal *fr)
{
	fr->pinsky.a.x = fr->axis_len / 2;
    fr->pinsky.a.y = MARGIN * fr->axis_len;
    fr->pinsky.b.x = MARGIN * fr->axis_len;
    fr->pinsky.b.y = fr->axis_len - MARGIN * fr->axis_len;
    fr->pinsky.c.x = fr->axis_len - MARGIN * fr->axis_len;
    fr->pinsky.c.y = fr->axis_len - MARGIN * fr->axis_len;
}