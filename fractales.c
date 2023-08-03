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

//Conjunto de mandelbrot
void mandelbrot(t_all *all)
{
    double tmp;
    t_fractal *f;
    t_move *mv;

    f = all->fractal;
    mv = all->mv;
    mlx_clear_window(all->win.mlx_ptr, all->win.win_ptr);
    f->row = -1;
    while (++f->row < all->win.h)
    {
        tmp = 0;
        f->col = -1;
        while (++f->col < all->win.w)
        {
            f->c_re = (f->col - all->win.w / 1.5 + mv->x) * 4.0 / (all->win.w * mv->z); // Mover horizontalmente (izquierda/derecha) con mv->x y mv->z
            f->c_im = (f->row - all->win.h / 2.0 + mv->y) * 4.0 / (all->win.h * mv->z); // Mover verticalmente (arriba/abajo) con mv->y y mv->z
            f->i = 0;
            f->x = 0;
            f->y = 0;
            ft_mndl(all->fractal, tmp);
            // while (f->i < 100 && ((f->x * f->x) + (f->y * f->y) <= 4))
            // {
            //     tmp = (f->x * f->x) - (f->y * f->y) + f->c_re;
            //     f->y = 2 * f->x * f->y + f->c_im;
            //     f->x = tmp;
            //     f->i++;
            // }
            if (f->i < 100)
                put_color_px(f->i, f, all->img);
            else
                my_mlx_pixel_put(all->img, f->col, f->row, 0x00000000);
        }
    }
    mlx_put_image_to_window(all->win.mlx_ptr, all->win.win_ptr, all->img->img, 0, 0);
}

void    ft_mndl(t_fractal *mndl, double tmp)
{
    while (mndl->i < 100 && ((mndl->x * mndl->x) + (mndl->y * mndl->y) <= 4))
    {
        tmp = (mndl->x * mndl->x) - (mndl->y * mndl->y) + mndl->c_re;
        mndl->y = 2 * mndl->x * mndl->y + mndl->c_im;
        mndl->x = tmp;
        mndl->i++;
    }
}

// Conjunto de Julia
/*Tengo que hacer que el conjunto se modifique dependiendo de las coordenadas en las que este el mouse
o tambien puedo introducirlas manualente por el teclado.*/
void julia(t_all *all)
{
    double tmp;
    t_fractal *f;
    t_move *mv;

    f = all->fractal;
    mv = all->mv;
    mlx_clear_window(all->win.mlx_ptr, all->win.win_ptr);
    f->row = -1;
    while (++f->row < all->win.h)
    {
        tmp = 0;
        f->col = -1;
        while (++f->col < all->win.w)
        {
            // Use the same c_re and c_im for every pixel to show the Julia set
            f->c_re = mv->x;
            f->c_im = mv->y;
            f->x = (f->col - all->win.w / 2.0) * 4.0 / (all->win.w * mv->z); // Scale x to fit the fractal
            f->y = (f->row - all->win.h / 2.0) * 4.0 / (all->win.h * mv->z); // Scale y to fit the fractal
            f->i = 0;
            while (f->i < 100 && ((f->x * f->x) + (f->y * f->y) <= 4))
            {
                tmp = (f->x * f->x) - (f->y * f->y) + f->c_re;
                f->y = 2 * f->x * f->y + f->c_im;
                f->x = tmp;
                f->i++;
            }
            if (f->i < 100)
                put_color_px(f->i, f, all->img);
            else
                my_mlx_pixel_put(all->img, f->col, f->row, 0x00000000);
        }
    }
    mlx_put_image_to_window(all->win.mlx_ptr, all->win.win_ptr, all->img->img, 0, 0);
}

