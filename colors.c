/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:48:02 by ncastell          #+#    #+#             */
/*   Updated: 2023/08/16 20:00:30 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"

void put_color_px(int i, t_fractal *fractal, t_img *img) {
    int res;
    
    res = i % 8;
    if (i < 1) {
        my_mlx_pixel_put(img, fractal->col, fractal->row, 0x00110000); // Color base
    } else {
        if (res == 0)
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x002266FF); // Azul intenso
        else if (res == 1)
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x003399FF); // Azul eléctrico
        else if (res == 2)
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x0055AAFF); // Azul brillante
        else if (res == 3)
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x0077BBFF); // Azul claro
        else if (res == 4)
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x0099CCFF); // Azul suave
        else if (res == 5)
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x00AADDFF); // Azul pastel
        else if (res == 6)
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x00BBEEFF); // Azul cielo
        else if (res == 7)
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x00DDEEFF); // Azul pálido
        else
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x00DDEEF0); // Negro
    }
}
