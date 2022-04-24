/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:32:10 by lde-alen          #+#    #+#             */
/*   Updated: 2022/04/24 20:21:39 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_put_pixel(t_fr *fr, int dp)
{
	int	pos;

	pos = (fr->fr.h + (fr->fr.w * WIN_W)) * 4;
	if (fr->fr.h < WIN_W && fr->fr.w < WIN_H && dp == fr->fr.it)
	{
		fr->im.d[pos] = 0x1;
		fr->im.d[pos + 1] = 0x1;
		fr->im.d[pos + 2] = 0x1;
	}
	else if (fr->fr.h < WIN_W && fr->fr.w < WIN_H)
	{
		fr->im.d[pos] = fr->cl.r + (dp * 69 / M_PI * M_PI);
		fr->im.d[pos + 1] = fr->cl.g + (dp * 69 * log10(M_PI));
		fr->im.d[pos + 2] = fr->cl.b + (dp * 69 * (1 / M_PI_2));
	}
}

void	fract_draw(t_fr *fr)
{
	static double	tmp_w;

	tmp_w = fr->fr.w;
	while (fr->fr.h < WIN_W)
	{
		fr->fr.w = tmp_w;
		while (fr->fr.w++ < WIN_H)
		{
			if (fr->fr.t == 1)
				ft_put_pixel(fr, mandelbrot(fr));
			if (fr->fr.t == 2)
				ft_put_pixel(fr, julia(fr));
			if (fr->fr.t == 3)
				ft_put_pixel(fr, mandelbar(fr));
			if (fr->fr.t == 4)
				ft_put_pixel(fr, mandelwhat(fr));
			if (fr->fr.t == 5)
				ft_put_pixel(fr, mandelclown(fr));
			if (fr->fr.t == 6)
				ft_put_pixel(fr, hheggy42(fr));
		}
		fr->fr.h += 1;
	}
	fr->fr.w = 0;
	fr->fr.h = 0;
}

int	fract_mod(int x, int y, t_fr *fr)
{
	if (fr->ms.st == 1 && (x > 0 && y > 0) && (x < WIN_W && y < WIN_H))
	{
		fr->ms.x = x;
		fr->ms.y = y;
		fract_re(fr);
	}
	return (0);
}
