# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvoldema <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 10:48:46 by mvoldema          #+#    #+#              #
#    Updated: 2023/03/10 10:48:48 by mvoldema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = main.c \
	0.c \
	1.c \
	2.c \
	3.c \
	4.c \
	5.c \
	6.c \


OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS += -Wall -Wextra -Werror -g -fPIE
RM = rm -f

all:	${NAME}

$(NAME): $(OBJ)
	@cp libft/libft.a libft.a
	@cp ft_printf/libftprintf.a libftprintf.a
	@cp minilibx-linuxv2/libmlx.a libmlx.a
	@$(CC) $(CFLAGS) $(OBJ) libft.a libftprintf.a libmlx.a -lXext -lX11 -lz -lm -o $(NAME)

clean: 
	@$(RM) libft.a
	@$(RM)  libftprintf.a
	@$(RM)  libmlx.a
	@$(RM)  $(OBJ)
	@echo "Cleaned"

fclean: clean
	@$(RM)  so_long
	@echo "FCleaned"

re: fclean all
	@echo "CLEANED AND RECOMPILED"

.PHONY: all clean fclean re

run: all
	./push_swap

5: all
	./push_swap "1 4 6 3 123"

