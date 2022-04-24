/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:14:20 by lde-alen          #+#    #+#             */
/*   Updated: 2022/04/24 21:24:37 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

/*
	Libraries
*/

# include "../libft/libft.h"
# ifdef __linux__
#  include "../miniLibx_linux/mlx.h"
# else
#  include "../miniLibx/mlx.h"
# endif

# ifdef __linux__
#  define MLB			1
#  define MRB			3
#  define MMB			2
#  define MWU			4
#  define MWD			5
#  define KEY_W			119
#  define KEY_S			115
#  define KEY_Z			122
#  define KEY_X			120
#  define KEY_C			99
#  define KEY_V			118
#  define KEY_R			114
#  define KEY_ESC		65307
#  define ARROW_UP		65362
#  define ARROW_DOWN	65364
#  define ARROW_LEFT	65361
#  define ARROW_RIGHT	65363
# else
#  define MLB			0x01
#  define MRB			0x02
#  define MMB			0x03
#  define MWU			0x04
#  define MWD			0x05
#  define KEY_W			0x0D
#  define KEY_S			0x01
#  define KEY_Z			0x06
#  define KEY_X			0x07
#  define KEY_C			0x08
#  define KEY_V			0x09
#  define KEY_R			0x0F
#  define KEY_ESC		0x35
#  define ARROW_UP		0x7E
#  define ARROW_DOWN	0x7D
#  define ARROW_LEFT	0x7B
#  define ARROW_RIGHT	0x7C
# endif

# include <unistd.h>
# include <stdlib.h>
# include <math.h>

/*
	Structures
*/

typedef struct s_ml
{
	void	*p;
	void	*w;
	void	*i;
}				t_ml;

typedef struct s_im
{
	char	*d;
	int		s;
	int		e;
	int		b;
}				t_im;

typedef struct s_cl
{
	int		r;
	int		g;
	int		b;
}				t_cl;

typedef struct s_tp
{
	int		t;
	int		dp;
	int		it;
	double	w;
	double	h;
	double	sc;
	double	l;
	double	xr;
	double	yi;
	double	jcr;
	double	jci;
}				t_tp;

typedef struct s_ms
{
	int		st;
	double	x;
	double	y;
}				t_ms;

typedef struct s_fr
{
	t_ml	ml;
	t_im	im;
	t_cl	cl;
	t_tp	fr;
	t_ms	ms;
	int		ac;
	char	**av;
	size_t	i;
}				t_fr;

/*
	Macraaazzzz for the window and scale
*/

# define WIN_W			1080
# define WIN_H			720
# define SC_LIM			10000000000
# define SC_PRC			1.3

/*
	Macraaazzzz for the Keyboard keys (MacOs QWERTY)
*/


// # define KEY_W			0x0D
// # define KEY_S			0x01
// # define KEY_Z			0x06
// # define KEY_X			0x07
// # define KEY_C			0x08
// # define KEY_V			0x09
// # define KEY_R			0x0F
// # define KEY_ESC		0x35
// # define ARROW_UP		0x7E
// # define ARROW_DOWN		0x7D
// # define ARROW_LEFT		0x7B
// # define ARROW_RIGHT	0x7C

/*
	Macraaazzzz for the Mouse keys (MacOs)
*/

// # define MLB			0x01
// # define MRB			0x02
// # define MMB			0x03
// # define MWU			0x04
// # define MWD			0x05

/*
	Prototypes
*/

int						ft_ms(int mousecode, int x, int y, t_fr *fr);
int						ft_key(int keycode, t_fr *fr);
int						fract_mod(int x, int y, t_fr *fr);

void					fract_ini(t_fr *fr);
void					fract_re(t_fr *fr);
void					fract_draw(t_fr *fr);
void					ft_put_pixel(t_fr *fr, int dp);
void					ft_print_usage(void);

int						mandelbrot(t_fr *fr);
int						mandelwhat(t_fr *fr);
int						mandelbar(t_fr *fr);
int						mandelclown(t_fr *fr);
int						hheggy42(t_fr *fr);
int						julia(t_fr *fr);

#endif
