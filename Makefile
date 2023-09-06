# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 13:49:45 by mapfenni          #+#    #+#              #
#    Updated: 2023/09/06 18:25:44 by mapfenni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = ./main.c ./src/parsing.c ./src/error.c ./src/pipex.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	make -C ./ft_printf
	make -C ./libft
	gcc ${CFLAGS} ${OBJS} ./ft_printf/libftprintf.a ./libft/libft.a -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS} ${BONUS}
	make clean -C ./ft_printf
	make clean -C ./libft

fclean: clean
	rm -f ${NAME}
	make clean -C ./ft_printf
	make clean -C ./libft

re: fclean all
	make fclean -C ./ft_printf
	make fclean -C ./libft