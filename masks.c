/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   masks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:00:45 by ncastell          #+#    #+#             */
/*   Updated: 2023/07/27 15:35:20 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int read_key(int press_key, t_img *img)
{
    if (press_key == ESC || !img)
        exit_tutorial(&img->win);
    return (0);
}

int read_mouse(int mouse_mv, t_all *all)
{
    if (mouse_mv == SCROLL_UP)
        zoom(all, 1);
    else if (mouse_mv == SCROLL_DOW)
        zoom(all, 2);
    return (0);
}

void    zoom(t_all *all, int n)
{
    t_move *mv;

    mv = all->move;
    if (n == 1)
        mv->z -= 0.5;
}