/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   masks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:00:45 by ncastell          #+#    #+#             */
/*   Updated: 2023/08/21 18:00:57 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"

int exit_win(t_all *f)
{
    if (f)
        mlx_destroy_window(f->win.mlx, f->win.win);
    exit(EXIT_SUCCESS);
}

int ft_move(int x, int y, t_all *f)
{
    f->mouse.x = x;
    f->mouse.y = y;
    return (0);
}

int read_key(int key, t_all *f)
{
    if (ft_strncmp(f->frac.set, "Julia", 5) == 0 && key == CTR)
    {
        mlx_hook(f->win.win, 6, 1L << 6, ft_move, f);
        f->mouse.re = f->frac.min_re + (double)f->mouse.x
            * (f->frac.max_re - f->frac.min_re) / W;
        f->mouse.im = f->frac.max_im + (double)f->mouse.y
            * (f->frac.min_im - f->frac.max_im) / W;
        fractol(f, -1, -1);
    }
    if (key == MORE_IT && f->mv.i < 1000)
        f->mv.i *= 2;
    else if (key == LESS_IT && f->mv.i > 1)
        f->mv.i /= 2;
    read_mv(key, f);
    fractol(f, -1, -1);
    if (key == ESC || !f->win.img)
        exit_win(f);
    return (0);
}

int read_mv(int key, t_all *f)
{
    if (key == K_UP)
        f->mv.y += 40.0;
    else if (key == K_DOWN)
        f->mv.y -= 40.0;
    else if (key == K_LEFT)
        f->mv.x -= 40.0;
    else if (key == K_RIGHT)
        f->mv.x += 40.0;
    else if (key == ZOOM_IN)
        f->mv.z -= 0.1;
    else if (key == ZOOM_OUT)
        f->mv.z += 0.1;
    return (0);
}

