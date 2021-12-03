/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:07:49 by lde-alen          #+#    #+#             */
/*   Updated: 2021/12/03 19:58:41 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	hheggy42(t_fr *fr)
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
		zr = (zr * zr * zr) - (zi * zi * zi) + 1 / tan(cr);
		zi = (2 * zi * zi) * tmp_zr * tmp_zr + 1 / tan(ci);
		fr->fr.dp += 1;
	}
	return (fr->fr.dp);
}
