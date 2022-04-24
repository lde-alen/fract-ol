# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 01:16:06 by lde-alen          #+#    #+#              #
#    Updated: 2022/04/24 23:01:17 by lde-alen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		fractol

LIBFT_NAME	=		libft.a
LIBFT_DIR	=		./libft

SRCS_DIR	=		./srcs/

SRCS		=		ft_mod.c				\
					ft_fract_extra.c		\
					ft_fract2.c				\
					ft_fract.c				\
					ft_draw.c				\
					main.c					\

OBJS		=		$(addprefix $(SRCS_DIR),$(SRCS:.c=.o))
OBJS_DIR_N	=		objs
OBJS_DIR	=		./objs

RM			=		rm -f

CP			=		cp

FLAGS		=		-Wall -Wextra -Werror

MLX_NAME	=	libmlx.a


UNAME := $(shell uname)

ifeq ($(UNAME),Linux)
	MLX		= ./miniLibx_linux
	MLX_COMPIL	= -L $(MLX) -lm -lXext -lX11 -Ofast
else
	MLX		= ./miniLibx
	MLX_COMPIL	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit -Ofast
endif

INCLUDES	+=		-I./includes/

CC			=		gcc

.c.o		:
					$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME)		:		$(OBJS)
					$(MAKE) -C ./libft
					$(MAKE) -C $(MLX)
					$(CC) $(MLX_COMPIL) $(FLAGS) $(OBJS) $(MLX)/$(MLX_NAME) $(LIBFT_DIR)/$(LIBFT_NAME) -o $(NAME)
					mkdir -p $(OBJS_DIR_N)
					mv $(OBJS) $(OBJS_DIR)

all			:		$(NAME)

clean		:
					$(MAKE) clean -C $(LIBFT_DIR)
					$(MAKE) clean -C $(MLX)
					$(RM) -r $(OBJS_DIR)/


fclean		:		clean
					$(MAKE) fclean -C $(LIBFT_DIR)
					$(RM) $(NAME)
					$(RM) $(LIBFT_DIR)/$(LIBFT_NAME)
					$(RM) $(MLX)/$(MLX_NAME)

re			:		fclean all

.PHONY		:		all bonus clean fclean re
