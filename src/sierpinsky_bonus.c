/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:45:17 by josfelip          #+#    #+#             */
/*   Updated: 2023/11/21 11:39:41 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"
#include <stdio.h>

void	ft_bresenham(t_point a, t_point b, t_fractal *fractal)
{
	uint32_t color = ft_pixel(255, 255, 255, 255);

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
			if (!ft_pt_validation(a))
			{
				printf("x=%d, y=%d\n", a.x, a.y);
            	mlx_put_pixel(fractal->canvas, a.x, a.y, color);
			}
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
			if (!ft_pt_validation(a))
			{
				printf("x=%d, y=%d\n", a.x, a.y);
            	mlx_put_pixel(fractal->canvas, a.x, a.y, color);
			}
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

void	ft_classic_artist(void *param)
{
	t_fractal	*fr;
	int			n;
	t_point		abc[3];
	
	fr = param;
	n = fr->iter_max;
	abc[0] = fr->pinsky.a;
	abc[1] = fr->pinsky.b;
	abc[2] = fr->pinsky.c;
	ft_sierpinsky(abc, n, fr);
}

void	ft_abc(t_fractal *fr)
{
    fr->pinsky.b.x = MARGIN * SIZE;
    fr->pinsky.b.y = SIZE - MARGIN * SIZE;
	fr->pinsky.a.x = SIZE / 2;
    fr->pinsky.a.y = MARGIN * SIZE;
    fr->pinsky.c.x = SIZE - MARGIN * SIZE;
    fr->pinsky.c.y = SIZE - MARGIN * SIZE;
}

int	ft_pt_validation(t_point a)
{
	return (a.x < MARGIN * SIZE || a.x > SIZE - MARGIN * SIZE || a.y < MARGIN * SIZE || a.y > SIZE - MARGIN * SIZE);
}
