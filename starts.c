/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:22:14 by ncastell          #+#    #+#             */
/*   Updated: 2023/07/25 16:31:21 by ncastell         ###   ########.fr       */
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