# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcremers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/28 14:25:14 by hcremers          #+#    #+#              #
#    Updated: 2021/07/28 14:25:18 by hcremers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= libftprintf.a

SCRS	= srcs/ft_printf.c \
		srcs/ft_strlen.c \
		srcs/ft_intlen.c \
		srcs/ft_uintlen.c \
		srcs/ft_putnbr_fd.c \
		srcs/ft_putstr_fd.c \
		srcs/ft_putchar_fd.c \
		srcs/ft_putunbr_fd.c \
		srcs/ft_putnbr_base.c \
		srcs/ft_uintlen_base.c \
		srcs/ft_putlong_base.c

OBJS	= ${SCRS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
