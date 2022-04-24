/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:20:07 by lde-alen          #+#    #+#             */
/*   Updated: 2022/04/24 20:21:54 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_print_usage(void)
{
	ft_putstr("\nUsage: ./fractol <fractal name> .\n\n");
	ft_putstr("List of fractals available:  ");
	ft_putstr("mandelbrot | mandelspike | mandelwhat");
	ft_putstr(" | mandelclown | julia | hheggy42 .\n\n");
	ft_putstr("NOTE: julia can be used without parameters or ");
	ft_putstr("set the parameters from the command line.\n\n");
	ft_putstr("Once the window is launched use the keyboard and");
	ft_putstr(" mouse to play with the fractal.\n\n");
	ft_putstr("Keybinds:\n");
	ft_putstr("ESC : Exit.\n");
	ft_putstr("W : Zoom in.\n");
	ft_putstr("S : Zoom out.\n");
	ft_putstr("Z : Increase iterations.\n");
	ft_putstr("X : Decrease iterations.\n");
	ft_putstr("C : Change color palette.\n");
	ft_putstr("R : Reset fractal settings.\n\n");
	ft_putstr("↑ : Move up.\n");
	ft_putstr("↓ : Move down.\n");
	ft_putstr("← : Move left.\n");
	ft_putstr("→ : Move right.\n\n");
	ft_putstr("Normal mouse mouvements will redraw with new inputs.\n\n");
	ft_putstr("LMB : Activate or Deactivate mouse.\n");
	ft_putstr("RMB : Change colors.\n");
	ft_putstr("SCR UP : Zoom out.\n");
	ft_putstr("SCR DOWN : Zoom in.\n\n");
}
