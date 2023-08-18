/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:33:45 by ncastell          #+#    #+#             */
/*   Updated: 2023/08/18 19:30:56 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"

void put_color_px(int i, t_all *f, int x, int y)
{
    int res;
    
    res = i % 8;
	if(i < 100)
	{
		if (res == 0)
			my_mlx_pixel_put(&f->win, x, y, 0x002266FF);
		else if (res == 1)
			my_mlx_pixel_put(&f->win, x, y, 0x003399FF);
		else if (res == 2)
			my_mlx_pixel_put(&f->win, x, y, 0x0055AAFF);
		else if (res == 3)
			my_mlx_pixel_put(&f->win, x, y, 0x0077BBFF);
		else if (res == 4)
			my_mlx_pixel_put(&f->win, x, y, 0x0099CCFF);
		else if (res == 5)
			my_mlx_pixel_put(&f->win, x, y, 0x00AADDFF);
		else if (res == 6)
			my_mlx_pixel_put(&f->win, x, y, 0x00BBEEFF);
		else if (res == 7)
			my_mlx_pixel_put(&f->win, x, y, 0x00DDEEFF);
	}
	else
		my_mlx_pixel_put(&f->win, x, y, 0x00000000);
}

int	mandelbrot(double cr, double ci)
{
	double	zx;
	double	zy;
	double	tmp;
	int		i;

	zx = 0;
	zy = 0;
	i = -1;
	while (zx * zx + zy * zy <= 4.0 && ++i < 100)
	{
		tmp = zx * zx - zy * zy + cr;
		zy = 2 * zx * zy + ci;
		zx = tmp;
	}
	return (i);
}

int	julia(t_all *f, double zx, double zy)
{
	double	tmp;
	int		i;

	i = 0;
	while (zx * zx + zy * zy <= 4.0 && ++i < 100)
	{
		tmp = 2 * zx * zy + f->mouse.im;
		zx = zx * zx - zy * zy + f->mouse.re;
		zy = tmp;
		i++;
	}
	return (i);
}

void    type(t_all *f, double re, double im, int x, int y)
{
	int i;

	i = 0;
    if (ft_strncmp(f->frac.set, "Mandelbrot", 10) == 0)
        i = mandelbrot(re, im);
    else if (ft_strncmp(f->frac.set, "Julia", 5) == 0)
        i = julia(f, re, im);
	put_color_px(i, f, x, y);
}

void    fractol(t_all *f, int x, int y)
{
    double re;
    double im;

    mlx_clear_window(f->win.mlx, f->win.win);
    while (++y < H)
    {
        x = -1;
		im = f->frac.max_im + ((double)y + f->mv.y) * (f->frac.min_im - f->frac.max_im) / (H * f->mv.z);
        while (++x < W)
        {
        	re = f->frac.min_re + ((double)x + f->mv.x) * (f->frac.max_re - f->frac.min_re) / (W * f->mv.z);
            type(f, re, im, x, y);
        }
    }
    mlx_put_image_to_window(f->win.mlx, f->win.win, f->win.img, 0, 0);
}
