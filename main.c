/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:28:29 by ncastell          #+#    #+#             */
/*   Updated: 2023/08/16 20:39:00 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"

int main(int ac, char **av)
{
    t_move      mv;
    t_img       img;
    t_win       win;
    t_fractal   fractal;
    t_all       all;
    
    if(!checker(ac, av[1]))
        exit(1);
    win = new_program(W, H, av[1]);
    start_fractal(&fractal);
    start_all(&img, win, &fractal, &mv, &all);
    img = new_img(win);
    all.fractal->set = av[1];
    ft_fractal(&all);
    mlx_hook(all.win.win_ptr, 17, 0, exit_win, &all.win);
    hooks(all);
    mlx_loop(all.win.mlx_ptr);
}

// Look if the arguments are okay
int checker(int ac, char *av)
{
    if (ac != 2)
    {
        write(1, "Invalid number of arguments!\n", 29);
        return (0);
    }
    else if (ft_strncmp(av, "Mandelbrot", 10) != 0
        && (ft_strncmp(av, "Julia", 5) != 0))
    {
        write(1, "Avaible fractals:\n", 18);
        write(1, "- Mandelbrot\n", 13);
        write(1, "- Julia\n", 8);
        return (0);
    }
    return (1);
}

void    hooks(t_all all)
{
    mlx_key_hook (all.win.win_ptr, read_key, &all);
    mlx_mouse_hook (all.win.win_ptr, read_mouse, &all);
}
