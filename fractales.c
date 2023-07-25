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

void    mandelbrot(t_fractal *mndl, t_win window, t_img *img)
{
    double      tmp;

    tmp = 0;
    while (++mndl->row < window.h)
    {
        mndl->col = -1;
        while (++mndl->col < window.w)
        {
            mndl->c_re = (mndl->col - window.w / 2.0) * 4.0 / window.w;
            mndl->c_im = (mndl->row - window.h / 2.0) * 4.0 / window.h;
            mndl->i = 0;
            mndl->x = 0;
            mndl->y = 0;
            while (mndl->i < 1000 && ((mndl->x * mndl->x)
                + (mndl->y * mndl->y) <= 4))
            {
                tmp = (mndl->x * mndl->x) - (mndl->y * mndl->y) + mndl->c_re;
                mndl->y = 2 * mndl->x * mndl->y + mndl->c_im;
                mndl->x = tmp;
                mndl->i++;
            }

            // if (mndl->i < 1000)
            //     my_mlx_pixel_put(img, mndl->col, mndl->row, 0x0071C55B);
            // else
            //     my_mlx_pixel_put(img, mndl->col, mndl->row, 0x00000000);

            put_color_px(mndl->i, mndl, img);
        }
    }
}
