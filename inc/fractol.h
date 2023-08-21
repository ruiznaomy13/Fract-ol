#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

# define LESS_IT 1
# define MORE_IT 13

# define H 1000
# define W 1000

# define ESC 53
# define CTR 256
# define S_DOWN 5
# define S_UP 4
# define K_LEFT 123
# define K_RIGHT 124
# define K_UP 126
# define K_DOWN 125
# define ZOOM_IN 78
# define ZOOM_OUT 69

int		exit_win(t_all *f);
int		read_key(int key, t_all *f);
int		read_mouse(int ms, t_all *f);
int		read_mv(int key, t_all *f);
int		scroll_hook(int button, int x, int y, t_all *all);
void	my_mlx_pixel_put(t_win *win, int x, int y, int color);
void	new_win(t_all *f, char *name);
void	start_all(t_all *f, char *name);
void	start_fractal(t_frac *frac);
void	fractol(t_all *f, int x, int y);
void	put_color_px(int i, t_all *f, int x, int y);
int		scroll_hook(int button, int x, int y, t_all *all);
int		mandelbrot(t_all *f, double cr, double ci);
int		julia(t_all *f, double zx, double zy);
#endif