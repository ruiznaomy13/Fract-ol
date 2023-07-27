#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <stdio.h>

# define ESC 53
# define H 1000
# define W 1000

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		h;
	int		w;
}			t_win;

typedef struct	s_img {
	t_win	win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	int		row;
	int		col;
	double	c_re;
	double	c_im;
	int		i;
	double	x;
	double	y;
}			t_fractal;

typedef struct s_move
{
	double	x;
	double	y;
	double	z;
}			t_move;

typedef struct s_all
{
	t_win		win;
	t_img		*img;
	t_fractal	*fractal;
	t_move		*mv;
}				t_all;


void    my_mlx_pixel_put(t_img *data, int x, int y, int color);
t_win	new_program(int w, int h, char *str);
t_img	new_img(t_win window);

void    start_all(t_all *all);
void    start_fractal(t_fractal *fractal);

/* FRACTALES */
void    mandelbrot(t_fractal *mndl, t_win window, t_img *img);

/* COLORS */
void    put_color_px(int i, t_fractal *fractal, t_img *img);
#endif