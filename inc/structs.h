/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:38:21 by ncastell          #+#    #+#             */
/*   Updated: 2023/08/21 18:00:35 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <mlx.h>

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
    int     i;
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

#endif