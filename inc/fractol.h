#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
#include <stdio.h>
#include <stdlib.h>

#define ITERATIONS 100

# define ESC 53
# define H 1000
# define W 1000
# define S_DOWN 4
# define S_UP 5
# define K_LEFT 123
# define K_RIGHT 124
# define K_UP 126
# define K_DOWN 125
# define ZOOM_IN 78
# define ZOOM_OUT 69

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
	char	*set;
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

void    start_all(t_img *img, t_win win, t_fractal *fractal, t_move *mv, t_all *all);
void    start_fractal(t_fractal *fractal);

/*HOOKS*/
void    hooks(t_all all);
int 	read_key(int press_key, t_all *all);
int 	read_mouse(int mouse_mv, t_all *all);

/*MASKS FT*/
int 	exit_win(t_win *win);
void    zoom(t_all *all, int n);

/* FRACTALES */
void	ft_mndl(t_fractal *f, t_move *mv, t_win win, double tmp);
void	fractol_set(t_all *fractal, char *set);
void	ft_fractal(t_all *all);
void	ft_julia(t_fractal *f, t_move *mv, t_win win, double tmp);

/* COLORS */
void    put_color_px(int i, t_fractal *fractal, t_img *img);

/* CHECKER */
int		checker(int ac, char *av);
void	ft_fractal(t_all *all);
#endif