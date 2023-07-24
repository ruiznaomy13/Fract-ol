/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:28:29 by ncastell          #+#    #+#             */
/*   Updated: 2023/07/24 22:04:40 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Define your my_mlx_pixel_put function here (same as before)

int main(void)
{
    void *mlx;
    void *mlx_win;
    int row = -1;
    int col = -1;
    double c_re = 0;
    double c_im = 0;
    int iteracion = 0;
    double x = 0;
    double y = 0;
    double x_temp = 0;
    t_data img;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
    img.img = mlx_new_image(mlx, 500, 500);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);

    while (++row < 500)
    {
        col = -1;
        while (++col < 500)
        {
            c_re = (col - 500 / 2.0) * 4.0 / 500;
            c_im = (row - 500 / 2.0) * 4.0 / 500;
            iteracion = 0;
            x = 0;
            y = 0;
            while (iteracion < 10000 && ((x * x) + (y * y) <= 4))
            {
                x_temp = (x * x) - (y * y) + c_re;
                y = 2 * x * y + c_im;
                x = x_temp;
                iteracion++;
            }
            if (iteracion < 10000)
                my_mlx_pixel_put(&img, col, row, 0x0071C55B); // Set pixel coordinates col and row
            else
                my_mlx_pixel_put(&img, col, row, 0x00000000); // Set pixel coordinates col and row
        }
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}