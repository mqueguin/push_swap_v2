# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 11:36:34 by mqueguin          #+#    #+#              #
#    Updated: 2021/08/28 18:54:35 by mqueguin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC = \033[0m
RED = \033[0;91m
ORANGE = \033[93m
GREEN = \x1b[32m
PURPLE = \033[0;95m
BLUE = \033[0;34m
BOLD = \033[1m
CYAN = \x1b[36m

SRCS		=	./srcs/push_swap.c\
				./srcs/check_errors.c\
				./srcs/get_pivot.c\
				./srcs/number_errors.c\
				./srcs/operations.c\
				./srcs/stack_managements.c\
				./srcs/radix_sort.c\
				./srcs/sort_5_numbers.c\
				./srcs/split_args.c

INCLUDES	=	./libft/libft.h \
				./includes/push_swap.h

HEAD		= ./includes/

LIBFT		= ./libft/libft.a

LIB_DIR	= ./libft/

NAME		= push_swap

CC			= clang

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

CFLAGS		=  -Wall -Wextra -Werror

.c.o:
		@${CC} ${CFLAGS} -I${HEAD} -c $< -o ${<:.c=.o}
		@echo "${GREEN}[ OK ] ${CYAN}${BOLD}${<:.s=.o}${NC}${NC}"


all:		${NAME}

${NAME}:	${OBJS}
			@make -C ${LIB_DIR}
			@echo "${GREEN}\nlibft.a has been created"
			@${CC} ${CFLAGS} -I${HEAD} -o ${NAME} $(OBJS) ${LIBFT}
			@echo "push_swap has been created\n${NC}"
			
clean:
			@make -C $(LIB_DIR) clean
			@${RM} ${OBJS} ${OBJS2} ${OBJS_B}
			@echo "\n${GREEN}[ OK ]${RED}	*.o files deleted${NC}"

fclean:		clean
			@make -C $(LIB_DIR) fclean
			@echo "${GREEN}[ OK ]${RED}	libft.a	deleted${NC}"
			@${RM} ${NAME} ${NAME2}
			@echo "${GREEN}[ OK ]${RED}	push_swap deleted\n${NC}"

re :		fclean all

.PHONY:		all	clean	fclean re
