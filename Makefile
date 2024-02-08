# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iksaiz-m <iksaiz-m@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 13:35:45 by iksaiz-m          #+#    #+#              #
#    Updated: 2024/02/08 16:04:39 by iksaiz-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =  ft_printf.c ft_functions.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rcs

OBJS = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@ $(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re