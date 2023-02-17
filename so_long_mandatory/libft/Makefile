# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 22:00:59 by acanelas          #+#    #+#              #
#    Updated: 2023/02/13 03:59:50 by acanelas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC =		ft_tolower.c \
			ft_toupper.c \
			ft_isalnum.c \
			ft_isalpha.c \
	    	ft_isascii.c \
			ft_isdigit.c \
     		ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
    		ft_memmove.c \
    		ft_memset.c \
			ft_putchar_fd.c \
    		ft_putendl_fd.c \
    		ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
     		ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_calloc.c \
			ft_bzero.c \
			ft_atoi.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstnew.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_printf.c \
			ft_putchar_ret_len.c \
			ft_putnumb.c \
			ft_putunsigned.c \
			ft_putstr_ret_len.c \
			ft_putadress.c \
			ft_puthex.c \
			get_next_line.c \
			ft_strjoin_free.c \

NAME = libft.a
CC = cc
CFLAGS = -c -Wall -Wextra -Werror  
ARCH = ar rcs
REMOVE = rm -f
OBF = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBF)
	$(ARCH) $(NAME) $(OBF)

clean:
	$(REMOVE) $(OBF)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
