/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   masks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:00:45 by ncastell          #+#    #+#             */
/*   Updated: 2023/07/28 17:15:28 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int read_key(int press_key, t_all *all)
{
    if (press_key == ESC || !all->img)
        exit_win(&all->img->win);
    return (0);
}

int read_mouse(int mouse_mv, t_all *all)
{
    if (mouse_mv == S_UP)
        zoom(all, 1);
    else if (mouse_mv == S_DOWN)
        zoom(all, 2);
    return (0);
}

void    zoom(t_all *all, int n)
{
    t_move *mv;

    mv = all->mv;
    if (n == 1)
        mv->z -= 0.5;
    else if (n == 2)
        mv->z += 0.5;
    mandelbrot(all->fractal, all->win, all->img);
}

int exit_win(t_win *win)
{
    if (win)
        mlx_destroy_window(win->mlx_ptr, win->win_ptr);
    exit(EXIT_SUCCESS);
}
