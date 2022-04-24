/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:14:45 by lde-alen          #+#    #+#             */
/*   Updated: 2022/04/24 22:06:24 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

/*
	This function parses the initial argument recieved by the program and check
	what type of fract is selected and the modifies it's according value for
	the rest of the execution. It also handles the errors in case the user
	enters the wrong parameters.
*/

static int	ft_select(char *name, t_fr *fr)
{
	fr->fr.t = 1;
	if (ft_strncmp(name, "help", ft_strlen("help")) == 0)
	{
		ft_print_usage();
		exit(0);
	}
	else if (ft_strncmp(name, "mandelbrot", ft_strlen("mandelbrot")) == 0
		&& fr->i == ft_strlen("mandelbrot"))
		fr->fr.t = 1;
	else if (ft_strncmp(name, "julia", ft_strlen("julia")) == 0 && fr->ac == 4)
		fr->fr.t = 2;
	else if (ft_strncmp(name, "mandelbar", 9) == 0 && fr->i == 10)
		fr->fr.t = 3;
	else if (ft_strncmp(name, "mandelwhat", ft_strlen("mandelwhat")) == 0
		&& fr->i == ft_strlen("mandelwhat"))
		fr->fr.t = 4;
	else if (ft_strncmp(name, "mandelclown", ft_strlen("mandelclown")) == 0
		&& fr->i == ft_strlen("mandelclown"))
		fr->fr.t = 5;
	else if (ft_strncmp(name, "hheggy42", ft_strlen("hheggy42")) == 0
		&& fr->i == ft_strlen("hheggy42"))
		fr->fr.t = 6;
	else
		ft_fputstr("Error: Invalid input. Please run ./fractol help\n");
	return (fr->fr.t);
}

/*
	Initializes the fract structure with the initial values required to draw
	before any change or update or button is pressed. This set the inital poits
	and values for all the fracts handled by the program.
*/

void	fract_ini(t_fr *fr)
{
	fr->fr.xr = -2.60;
	fr->fr.yi = -1.20;
	fr->ms.st = 1;
	fr->fr.sc = 300.00;
	fr->fr.it = 30;
	fr->fr.w = 0;
	fr->ms.x = WIN_W / 2;
	fr->ms.y = WIN_H / 2;
	if (fr->fr.t == 2)
	{
		fr->fr.it = 100;
		if (fr->ac == 4)
		{
			fr->fr.jcr = ft_atof(fr->av[2]);
			fr->fr.jci = ft_atof(fr->av[3]);
		}
	}
}

/*
	Function destroys the old image that was previously displayed then redraws
	the new fract with the new coordinates colors and depth as well as mouse
	position and update the currents strings displayed on the window.
*/

void	fract_re(t_fr *fr)
{
	if (fr->fr.it <= 0)
		fr->fr.it = 0;
	mlx_destroy_image(fr->ml.p, fr->ml.i);
	fr->ml.i = mlx_new_image(fr->ml.p, WIN_W, WIN_H);
	fr->im.d = mlx_get_data_addr(fr->ml.i, &fr->im.b, &fr->im.s, &fr->im.e);
	fract_draw(fr);
	mlx_put_image_to_window(fr->ml.p, fr->ml.w, fr->ml.i, 0, 0);
}

/*
	In the main, check the basic amount of arguments required for the program
	to run, malloc the initial structure that will be used throught the whole
	code. Initializes the structes int the following order: mlx init, window,
	image, fractol. then calls the hook in order to handle the mouse events
	as well as the keys and the basic loop to keep the window open while the
	program runs.
*/

void	ft_mlx_init(t_fr *fr)
{
	fr->ml.p = mlx_init();
	fr->ml.w = mlx_new_window(fr->ml.p, WIN_W, WIN_H, fr->av[1]);
	fr->ml.i = mlx_new_image(fr->ml.p, WIN_W, WIN_H);
	fr->im.d = mlx_get_data_addr(fr->ml.i, &fr->im.b, &fr->im.s, &fr->im.e);
}

int	main(int ac, char **av)
{
	t_fr	fr;

	if (ac == 2
		|| (ac == 4 && ((ft_strncmp(av[1], "julia", ft_strlen("julia")) == 0))))
	{
		fr.ac = ac;
		fr.av = av;
		fr.i = ft_strlen(av[1]);
		if (!ft_select(av[1], &fr))
			ft_fputstr("Error: Invalid input please try again.");
		ft_mlx_init(&fr);
		fract_ini(&fr);
		fract_re(&fr);
		mlx_hook(fr.ml.w, 2, 3, ft_key, &fr);
		mlx_hook(fr.ml.w, 4, 3, ft_ms, &fr);
		mlx_mouse_hook(fr.ml.w, ft_ms, &fr);
		mlx_hook(fr.ml.w, 6, 1L << 6, fract_mod, &fr);
		mlx_loop(fr.ml.p);
	}
	else
		ft_print_usage();
	return (0);
}
