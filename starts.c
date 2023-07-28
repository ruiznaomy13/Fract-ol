/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:22:14 by ncastell          #+#    #+#             */
/*   Updated: 2023/07/28 14:22:52 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    start_fractal(t_fractal *fractal)
{
    fractal->row = -1;
    fractal->col = -1;
    fractal->c_im = 0;
    fractal->c_re = 0;
    fractal->i = 0;
    fractal->x = 0;
    fractal->y = 0;
}

void    start_mv(t_move *move)
{
    move->x = 0.0;
    move->y = 0.0;
    move->z = 1.0;  
}

void    start_all(t_img *img, t_win win, t_fractal *fractal, t_move *mv, t_all *all)
{
    start_mv(mv);
    all->fractal = fractal;
    all->img = img;
    all->win = win;
    all->mv = mv;
}
