# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apodader <apodader@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 11:49:18 by apodader          #+#    #+#              #
#    Updated: 2023/02/20 17:08:20 by apodader         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS		= $(shell find "." -name "*.c")

OBJS		= ${SRCS:.c=.o}

CC		= gcc
RM		= rm -rf
CFLAGS		= -Wall -Wextra -Werror
AR		= ar csr

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all : ${NAME}

$(NAME) : ${OBJS}
	@${AR} libft.a ${OBJS}

clean :
	@${RM} ${OBJS}

fclean : clean
	@${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re .c.o
