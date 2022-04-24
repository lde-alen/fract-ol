/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:09:57 by lde-alen          #+#    #+#             */
/*   Updated: 2022/04/24 21:15:42 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

/*
	Zoom in function
*/
static void	ft_zoom_in(int x, int y, t_fr *fr)
{
	if (fr->fr.sc >= SC_LIM)
	{
		fr->fr.sc = SC_LIM;
		return ;
	}
	if (fr->ms.st == 1)
	{
		fr->ms.x = x;
		fr->ms.y = y;
	}
	fr->fr.xr = (x / fr->fr.sc + fr->fr.xr) - ((fr->fr.sc * SC_PRC) / 2);
	fr->fr.xr += ((fr->fr.sc * SC_PRC) / 2) - (x / (fr->fr.sc * SC_PRC));
	fr->fr.yi = (y / fr->fr.sc + fr->fr.yi) - ((fr->fr.sc * SC_PRC) / 2);
	fr->fr.yi += ((fr->fr.sc * SC_PRC) / 2) - (y / (fr->fr.sc * SC_PRC));
	fr->fr.sc *= SC_PRC;
}

/*

*/
static void	ft_zoom_out(t_fr *fr)
{
	fr->fr.xr = (fr->ms.x / fr->fr.sc + fr->fr.xr) - ((fr->fr.sc / SC_PRC) / 2);
	fr->fr.xr += ((fr->fr.sc / SC_PRC) / 2) - (fr->ms.x / (fr->fr.sc / SC_PRC));
	fr->fr.yi = (fr->ms.y / fr->fr.sc + fr->fr.yi) - ((fr->fr.sc / SC_PRC) / 2);
	fr->fr.yi += ((fr->fr.sc / SC_PRC) / 2) - (fr->ms.y / (fr->fr.sc / SC_PRC));
	fr->fr.sc /= SC_PRC;
}

static void	ft_rng_clr(t_fr *fr)
{
	fr->cl.r = rand() * (0x2F + 0x42);
	fr->cl.g = rand() * (0x6F + 0x42);
	fr->cl.b = rand() * (0x9F + 0x42);
}

int	ft_ms(int mousecode, int x, int y, t_fr *fr)
{
	if (x > 0 && y > 0 && x < WIN_W && y < WIN_H)
	{
		if (mousecode == MWU)
			ft_zoom_in(x, y, fr);
		else if (mousecode == MWD)
			ft_zoom_out(fr);
		else if (mousecode == MMB)
			fract_ini(fr);
		else if (mousecode == MRB)
			ft_rng_clr(fr);
		else if (mousecode == MLB)
		{
			if (fr->ms.st == 0)
				fr->ms.st = 1;
			else
				fr->ms.st = 0;
		}
		fract_re(fr);
	}
	return (0);
}

/*
	Modifies directly the according structure variable based on the key pressed.
*/

int	ft_key(int keycode, t_fr *fr)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == ARROW_UP)
		fr->fr.yi -= 30 / fr->fr.sc;
	else if (keycode == ARROW_LEFT)
		fr->fr.xr -= 30 / fr->fr.sc;
	else if (keycode == ARROW_DOWN)
		fr->fr.yi += 30 / fr->fr.sc;
	else if (keycode == ARROW_RIGHT)
		fr->fr.xr += 30 / fr->fr.sc;
	else if (keycode == KEY_W)
		ft_zoom_in((WIN_W / 2), (WIN_H / 2), fr);
	else if (keycode == KEY_S)
		ft_zoom_out(fr);
	else if (keycode == KEY_R)
		fract_ini(fr);
	else if (keycode == KEY_C)
		ft_rng_clr(fr);
	else if (keycode == KEY_Z)
		fr->fr.it += 5;
	else if (keycode == KEY_X)
		fr->fr.it -= 5;
	fract_re(fr);
	return (0);
}
