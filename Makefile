# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 04:04:08 by acanelas          #+#    #+#              #
#    Updated: 2023/02/21 03:12:56 by acanelas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_BONUS = srcs_bonus/check_map.c \
		srcs_bonus/confirm_map.c \
		srcs_bonus/delete_graphic.c \
		srcs_bonus/init_graphic.c \
		srcs_bonus/moves.c \
		srcs_bonus/more_utils.c \
		srcs_bonus/utils.c \
		srcs_bonus/exit_animation.c \
		srcs_bonus/main.c \

SRCS =	srcs/check_map.c \
		srcs/confirm_map.c \
		srcs/delete_graphic.c \
		srcs/init_graphic.c \
		srcs/moves.c \
		srcs/more_utils.c \
		srcs/utils.c \
		srcs/main.c \

NAME = so_long
NAME_BONUS = so_long_bonus
RM = rm -rf
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
CCMLX = -L ./minilibx -lmlx -Ilmlx -lXext -lX11

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(CCMLX) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(CCMLX) -o $(NAME_BONUS)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	
re: fclean all

.PHONY: all clean fclean re
