/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:11:17 by lde-alen          #+#    #+#             */
/*   Updated: 2021/12/04 01:46:48 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	julia(t_fr *fr)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fr->fr.dp = 0;
	cr = (fr->ms.x - (210.0 / 2.0) - WIN_W) / ((double)WIN_W * 2) + 0.15;
	ci = (fr->ms.y - (320.0 / 2.0) - WIN_H) / (double)WIN_H - 0.15;
	if (fr->ms.st == 0 && fr->ac == 4)
	{
		cr = fr->fr.jcr;
		ci = fr->fr.jci;
	}
	zi = fr->fr.w / fr->fr.sc + fr->fr.yi;
	zr = fr->fr.h / fr->fr.sc + fr->fr.xr;
	while ((zr * zr) + (zi * zi) < 4 && fr->fr.dp < fr->fr.it)
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		fr->fr.dp += 1;
	}
	return (fr->fr.dp);
}

int	mandelbrot(t_fr *fr)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fr->fr.dp = 0;
	zr = (fr->ms.x - WIN_W) / ((double)WIN_W * 2) + 0.25;
	zi = (fr->ms.y - WIN_H) / ((double)WIN_H) + 0.50;
	ci = fr->fr.w / fr->fr.sc + fr->fr.yi;
	cr = fr->fr.h / fr->fr.sc + fr->fr.xr;
	while ((zr * zr) + (zi * zi) < 4 && fr->fr.dp < fr->fr.it)
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		fr->fr.dp += 1;
	}
	return (fr->fr.dp);
}

int	mandelbar(t_fr *fr)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fr->fr.dp = 0;
	zr = (fr->ms.x - WIN_W) / ((double)WIN_W * 2) + 0.25;
	zi = (fr->ms.y - WIN_H) / ((double)WIN_H) + 0.50;
	ci = fr->fr.w / fr->fr.sc + fr->fr.yi;
	cr = fr->fr.h / fr->fr.sc + fr->fr.xr;
	while ((zr * zr) + (zi * zi) < 8 && fr->fr.dp < fr->fr.it)
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = (-2 * zi) * tmp_zr + ci;
		fr->fr.dp += 1;
	}
	return (fr->fr.dp);
}

int	mandelwhat(t_fr *fr)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fr->fr.dp = 0;
	zr = (fr->ms.x - WIN_W) / ((double)WIN_W * 2) + 0.25;
	zi = (fr->ms.y - WIN_H) / ((double)WIN_H) + 0.50;
	ci = fr->fr.w / fr->fr.sc + fr->fr.yi;
	cr = fr->fr.h / fr->fr.sc + fr->fr.xr;
	while ((zr * zi) + (zi * zr) < 4 && fr->fr.dp < fr->fr.it)
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + sin(cr);
		zi = (2 * zi) * tmp_zr + sin(ci);
		fr->fr.dp += 1;
	}
	return (fr->fr.dp);
}

int	mandelclown(t_fr *fr)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fr->fr.dp = 0;
	zr = (fr->ms.x - WIN_W) / ((double)WIN_W * 2) + 0.25;
	zi = (fr->ms.y - WIN_H) / ((double)WIN_H) + 0.50;
	ci = fr->fr.w / fr->fr.sc + fr->fr.yi;
	cr = fr->fr.h / fr->fr.sc + fr->fr.xr;
	while ((zr * zi) + (zi * zr) < 4 && fr->fr.dp < fr->fr.it)
	{
		tmp_zr = zr;
		zr = (zr * zr * zr) - (zi * zi * zi) + sin(cr);
		zi = (2 * zi * zi) * tmp_zr * tmp_zr + sin(ci);
		fr->fr.dp += 1;
	}
	return (fr->fr.dp);
}
