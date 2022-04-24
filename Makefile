# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 01:16:06 by lde-alen          #+#    #+#              #
#    Updated: 2022/04/24 20:41:51 by lde-alen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		fractol

LIBFT		=		./libft/libft.a

SRCS		=		./srcs/ft_mod.c					\
					./srcs/ft_fract_extra.c			\
					./srcs/ft_fract2.c				\
					./srcs/ft_fract.c				\
					./srcs/ft_draw.c				\
					./srcs/main.c					\

OBJS		=		$(SRCS:.c=.o)

RM			=		rm -f

CP			=		cp

FLAGS		=		-Wall -Wextra -Werror

# MLX_FLAGS	=		-framework OpenGL -framework AppKit -Ofast
# MLX_FLAGS	=		-lm -lXext -lX11 -Ofast

UNAME := $(shell uname)

ifeq ($(UNAME),Linux)
	MLX		= ./miniLibx_linux/
	MLX_LNK	= -L $(MLX) -lm -lXext -lX11 -Ofast
else
	MLX		= ./miniLibx/
	MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit -Ofast
endif

INCLUDES	+=		-I./includes/

CC			=		gcc

.c.o		:
					$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME)		:		$(OBJS)
					$(MAKE) -C ./libft
					$(MAKE) -C $(MLX)
					$(CP) $(LIBFT) ./srcs/
					$(CP) $(MLX)/libmlx.a ./srcs/
					$(CC) $(MLX_LNK) $(FLAGS) $(SRCS) ./srcs/libmlx.a ./srcs/libft.a -o $(NAME)

all			:		$(NAME)

clean		:
					$(MAKE) clean -C ./libft
					$(MAKE) clean -C $(MLX)
					$(RM) $(OBJS)

fclean		:		clean
					$(MAKE) fclean -C ./libft
					$(RM) $(NAME)
					$(RM) ./srcs/libft.a
					$(RM) ./srcs/libmlx.a

re			:		fclean all

.PHONY		:		all bonus clean fclean re
