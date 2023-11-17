/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:45:17 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/17 17:33:39 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	ft_skytrans(t_complex *p, t_fractal *fr, t_pixel px)
{
	p->x = (+1.0) * fr->a * px.w + fr->b.x;
	p->y = (+1.0) * fr->a * px.h + fr->b.y;
}

void	ft_bresenham(t_point a, t_point b, t_fractal *fractal)
{
	uint32_t color = ft_pixel(255, 255, 255, 255);

	t_point	tmp;

    int32_t    dis;

    int32_t    dx;
    int32_t    dy;
    int32_t i = 0;

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
			ft_rev_strans(&tmp, a, fractal);
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
			ft_rev_strans(&tmp, a, fractal);
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
	fr->pinsky.a = ft_strans(fr->pinsky.a, fr);
	fr->pinsky.b = ft_strans(fr->pinsky.b, fr);
	fr->pinsky.c = ft_strans(fr->pinsky.c, fr);
	n = fr->iter_max;
	ft_sierpinsky(fr->pinsky.a, fr->pinsky.b, fr->pinsky.c, n, fr);
}