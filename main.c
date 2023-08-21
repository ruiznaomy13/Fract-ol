/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:28:29 by ncastell          #+#    #+#             */
/*   Updated: 2023/08/21 19:41:12 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"

int	checker(int ac, char *av)
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
		write(1, "- Julin", 8);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_all	f;

	if (!checker(ac, av[1]))
		exit(1);
	new_win(&f, av[1]);
	start_all(&f, av[1]);
	fractol(&f, -1, -1);
	mlx_put_image_to_window(f.win.mlx, f.win.win, f.win.img, 0, 0);
	mlx_hook(f.win.win, 17, 0, exit_win, &f);
	mlx_key_hook(f.win.win, read_key, &f);
	mlx_loop(f.win.mlx);
	return (EXIT_SUCCESS);
}
