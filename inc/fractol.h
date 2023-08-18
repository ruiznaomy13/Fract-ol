#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
#include <stdio.h>
#include <stdlib.h>

#define ITERATIONS 100

# define ESC 53
# define CTR 256
# define H 1000
# define W 1000
# define S_DOWN 5
# define S_UP 4
# define K_LEFT 123
# define K_RIGHT 124
# define K_UP 126
# define K_DOWN 125
# define ZOOM_IN 78
# define ZOOM_OUT 69


typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_mouse
{
	double	re;
	double	im;
	double	zoom;
	int		x;
	int		y;
}	t_mouse;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits;
	int		line;
	int		end;
}	t_win;

typedef struct s_frac
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	x;
	double	y;
	char	*set;
}	t_frac;

typedef struct s_move
{
	double	x;
	double	y;
	double	z;
}			t_move;

typedef struct s_all
{
	t_move	mv;
	t_win	win;
	t_frac	frac;
	t_mouse mouse;
}	t_all;

int		exit_win(t_all *f);
int		read_key(int key, t_all *f);
int		read_mouse(int ms, t_all *f);
void	my_mlx_pixel_put(t_win *win, int x, int y, int color);
void	new_win(t_all *f, char *name);
void	start_all(t_all *f, char *name);
void	start_fractal(t_frac *frac);
void	fractol(t_all *f, int x, int y);
#endif