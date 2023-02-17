# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 04:04:08 by acanelas          #+#    #+#              #
#    Updated: 2023/02/16 20:50:07 by acanelas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs_bonus/check_map.c \
		srcs_bonus/confirm_map.c \
		srcs_bonus/delete_graphic.c \
		srcs_bonus/init_graphic.c \
		srcs_bonus/moves.c \
		srcs_bonus/more_utils.c \
		srcs_bonus/check_path.c \
		srcs_bonus/utils.c \
			main.c \

NAME = so_long_bonus
RM = rm -rf
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
CCMLX = -L ./minilibx -lmlx -Ilmlx -lXext -lX11

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(CCMLX) -o $(NAME)

bonus: all

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re