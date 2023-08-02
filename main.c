/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:28:29 by ncastell          #+#    #+#             */
/*   Updated: 2023/08/02 15:00:33 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main()
{
    t_move      mv;
    t_img       img;
    t_win       win;
    t_fractal   fractal;
    t_all   all;
    
    start_fractal(&fractal);
    win = new_program(W, H, "MANDELBROT");
    img = new_img(win);
    start_all(&img, win, &fractal, &mv, &all);
    mandelbrot(&all);
    // mlx_put_image_to_window(all.win.mlx_ptr, all.win.win_ptr, all.img->img, 0, 0);
    mlx_key_hook (all.win.win_ptr, read_key, &all);
    // mlx_mouse_hook (all.win.win_ptr, read_mouse, &all);
    mlx_hook(all.win.win_ptr, 17, 0, exit_win, &all.win);
    mlx_loop(all.win.mlx_ptr);
}
