/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:28:29 by ncastell          #+#    #+#             */
/*   Updated: 2023/07/27 19:21:26 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main()
{
    // t_all       all;
    // t_img       img;
    // t_win       window;
    // t_fractal   mndl;
    t_all   all;
    
    // start_fractal(&mndl);
    // window = new_program(W, H, "MANDELBROT");
    // img = new_img(window);
    start_all(&all);
    mandelbrot(all.fractal, all.win, all.img);
    mlx_put_image_to_window(all.win.mlx_ptr, all.win.win_ptr, all.img->img, 0, 0);
    mlx_loop(all.win.mlx_ptr);
}
