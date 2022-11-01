# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 10:28:32 by lmedrano          #+#    #+#              #
#    Updated: 2022/11/01 16:06:34 by lmedrano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC		= gcc

CFLAGS		= -Wall -Werror -Wextra

LIB		= ar rc

RM		= rm -f

.c.o:		
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		${LIB} ${NAME} ${OBJS}

all:		${NAME}

clean:		
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re bonus
