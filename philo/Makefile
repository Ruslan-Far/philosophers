# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 14:51:32 by ljaehaer          #+#    #+#              #
#    Updated: 2022/03/10 09:50:15 by ljaehaer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

SRC			=	src/philo.c src/utils.c src/gen_philos.c src/checks.c src/routine.c src/run_routine.c

HEADER		=	inc/philo.h

OBJ			=	${SRC:%.c=%.o}

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -pthread
RM			=	rm -f

.PHONY	:		all clean fclean re

all		:		${NAME}
	
${NAME}	:		${OBJ}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ}

%.o		:		%.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

clean	:		
	${RM} ${OBJ} ${OBJ_B}

fclean	:		clean
	${RM} ${NAME}

re		:		fclean all
