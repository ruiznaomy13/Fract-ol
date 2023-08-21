/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:30:47 by ncastell          #+#    #+#             */
/*   Updated: 2023/08/21 18:00:40 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"

void	my_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line + x * (win->bits / 8));
	*(unsigned int*)dst = color;
}

void    new_win(t_all *f, char *name)
{
    f->win.mlx = mlx_init();
	f->win.win = mlx_new_window(f->win.mlx, W, H, name);
	f->win.img = mlx_new_image(f->win.mlx, W, H);
	f->win.addr = mlx_get_data_addr(f->win.img, &f->win.bits, &f->win.line,
								&f->win.end);
}

void    start_all(t_all *f, char *name)
{
    f->frac.min_re = 0;
    f->frac.max_re = 0;
    f->frac.min_im = 0;
    f->frac.max_im = 0;
    f->frac.x = 0;
    f->frac.y = 0;
    f->mv.i = 10;
    f->mv.x = 1.0;
    f->mv.y = 1.0;
    f->mv.z = 1.0;
    f->frac.set = name;
    start_fractal(&f->frac);
}

void    start_fractal(t_frac *frac)
{
    if (ft_strncmp(frac->set, "Mandelbrot", 10) == 0)
    {
        frac->min_re = -2.0;
        frac->max_re = 1.0;
        frac->min_im = -1.5;
        frac->max_im = frac->min_im + (frac->max_re - frac->min_re)
            * H / W;
    }
    else if (ft_strncmp(frac->set, "Julia", 5) == 0)
    {
        frac->min_re = -2.0;
        frac->max_re = 2.0;
        frac->min_im = -2.0;
        frac->max_im = frac->min_im + (frac->max_re - frac->min_re)
            * H / W;   
    }
}
