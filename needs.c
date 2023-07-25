/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:30:47 by ncastell          #+#    #+#             */
/*   Updated: 2023/07/25 16:35:27 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}


t_win new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

t_img	new_img(t_win window)
{
	t_img	image;

	image.win = window;
	image.img = mlx_new_image(window.mlx_ptr, window.w, window.h);
	image.addr = mlx_get_data_addr(image.img, &(image.bpp), 
			&(image.line_len), &(image.endian));
	return (image);
}
