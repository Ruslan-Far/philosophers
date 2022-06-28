# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 14:51:32 by ljaehaer          #+#    #+#              #
#    Updated: 2022/03/12 20:59:39 by ljaehaer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo_bonus

SRC			=	src/philo_bonus.c src/exits_bonus.c src/init_bonus.c src/simulate_bonus.c src/utils_bonus.c\
				src/run_routine_one_bonus.c src/run_routine_odd_bonus.c src/run_routine_even_bonus.c\
				src/ft_take_forks_bonus.c src/ft_eat_bonus.c src/ft_sleep_bonus.c src/ft_think_bonus.c

HEADER		=	inc/philo_bonus.h

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
