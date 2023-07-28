/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales->c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:33:45 by ncastell          #+#    #+#             */
/*   Updated: 2023/07/25 16:38:37 by ncastell         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    mandelbrot(t_all *all)
{
    double      tmp;
    t_fractal   *f;

    f = all->fractal;
    while (++f->row < all->win.h)
    {
        tmp = 0;
        f->col = -1;
        while (++f->col < all->win.w)
        {
            f->c_re = (f->col - all->win.w / 1.5) * (3.0 / all->mv->z) / all->win.w;
            f->c_im = (f->row - all->win.h / 2.0) * (3.0 / all->mv->z) / all->win.h;
            f->i = 0;
            f->x = 0;
            f->y = 0;
            while (f->i < 1000 && ((f->x * f->x)
                + (f->y * f->y) <= 4))
            {
                tmp = (f->x * f->x) - (f->y * f->y) + f->c_re;
                f->y = 2 * f->x * f->y + f->c_im;
                f->x = tmp;
                f->i++;
            }

            if (f->i < 1000)
                put_color_px(f->i, f, all->img);
            else
                my_mlx_pixel_put(all->img, f->col, f->row, 0x00000000);
        }
    }
}
