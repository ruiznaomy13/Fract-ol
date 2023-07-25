/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:28:29 by ncastell          #+#    #+#             */
/*   Updated: 2023/07/25 16:49:26 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main()
{
    t_img       img;
    t_win       window;
    t_fractal   mndl;
    
    start_fractal(&mndl);
    window = new_program(500, 500, "MANDELBROT");
    img = new_img(window);
    mandelbrot(&mndl, window, &img);
    mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, img.img, 0, 0);
    mlx_loop(window.mlx_ptr);
}
