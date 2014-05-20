# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/07 21:28:19 by ael-kadh          #+#    #+#              #
#    Updated: 2014/05/11 11:17:31 by ael-kadh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo
SRC				=	main.c init.c philosof.c norme.c mlx.c draw.c draw2.c
HEAD			=	philo.h lists.h
OBJ				=	$(SRC:.c=.o)
FLAGS			=	-Wall -Wextra -Werror -g3

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[35m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$(C_NO)
OK				=	$(C_OK)OK$(C_NO)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@cc $(OBJ) -L libft -lft -lpthread -L /usr/X11/lib -lmlx -lXext -lX11\
			libft/printf/libftprintf.a -o $(NAME)
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)

%.o : %.c
	@cc $(FLAGS) -c -I libft/ -I /usr/X11/include -I /usr/include\
					-I libft/printf/includes $<

clean :
	@make -C libft clean
	@rm -f $(OBJ)
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)


fclean : clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "Delete" [ $(NAME) ] $(OK)

re : fclean all

.PHONY: all clean fclean re
