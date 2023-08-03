/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   masks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:00:45 by ncastell          #+#    #+#             */
/*   Updated: 2023/08/02 15:01:14 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int read_key(int press_key, t_all *all)
{
    if (press_key == K_UP)
        all->mv->y += 20.0;
    else if (press_key == K_DOWN)
        all->mv->y -= 20.0;
    else if (press_key == K_LEFT)
        all->mv->x += 20.0;
    else if (press_key == K_RIGHT)
        all->mv->x -= 20.0;
    else if (press_key == ZOOM_IN)
        all->mv->z += 0.1;
    else if (press_key == ZOOM_OUT)
        all->mv->z -= 0.1;
    mandelbrot(all);
    if (press_key == ESC || !all->img)
        exit_win(&all->img->win);
    return (0);
}

int read_mouse(int mouse_mv, t_all *all)
{
    if (mouse_mv == S_UP)
        all->mv->z += 0.1;
    else if (mouse_mv == S_DOWN)
        zall->mv->z -= 0.1;
    return (0);
}

int exit_win(t_win *win)
{
    if (win)
        mlx_destroy_window(win->mlx_ptr, win->win_ptr);
    exit(EXIT_SUCCESS);
}
