/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:48:02 by ncastell          #+#    #+#             */
/*   Updated: 2023/07/25 17:07:56 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    put_color_px(int i, t_fractal *fractal, t_img *img)
{
    if (i > 0 && i < 2)
        my_mlx_pixel_put(img, fractal->col, fractal->row, 0x00E8D7F1);
    else if (i > 2 && i < 5)
        my_mlx_pixel_put(img, fractal->col, fractal->row, 0x00D3BCCC);
    else if (i > 5 && i < 8)
        my_mlx_pixel_put(img, fractal->col, fractal->row, 0x00A167A5);
    else if (i > 8 && i < 10)
        my_mlx_pixel_put(img, fractal->col, fractal->row, 0x004A306D);
    else if (i > 10 && i < 12)
        my_mlx_pixel_put(img, fractal->col, fractal->row, 0x000E273C);
    else
        my_mlx_pixel_put(img, fractal->col, fractal->row, 0x00000000);
}