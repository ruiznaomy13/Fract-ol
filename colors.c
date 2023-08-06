/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:48:02 by ncastell          #+#    #+#             */
/*   Updated: 2023/08/06 20:15:43 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"

void    put_color_px(int i, t_fractal *fractal, t_img *img)
{
    int res;

    res = i % 4;
    if (i < 14)
        my_mlx_pixel_put(img, fractal->col, fractal->row, 0x00110000);
    else {
        if (res == 0)
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x00FF81FF);
        else if (res == 1)
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x00D3BCCC);
        else if (res == 2)
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x00A167A5);
        else if (res == 3)
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x004A306D);
        else if (res == 4)
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x000E273C);
        else
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x00E8D7F1);
    }
}