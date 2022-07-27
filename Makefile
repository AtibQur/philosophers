# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 10:34:59 by hqureshi          #+#    #+#              #
#    Updated: 2022/07/27 14:27:38 by hqureshi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

CC			= gcc 
CFLAGS		= -Wall -Werror -Wextra

all:		$(NAME)

SRCS		= sources/main.c \
			sources/philosophers_utils.c \
			sources/init_program.c \
			sources/check_errors.c \
			sources/ft_atoi.c \
			sources/philosophers.c \
			sources/check_philosophers.c \
			sources/action_info.c \
			
INCS		= ./includes/philosophers.h

OBJS		= $(SRCS:.c=.o)

$(NAME):		$(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "\033[0;32mPhilosophers are ready!\033[0m"

clean:
		@rm -f $(OBJS)
		@echo "\033[0;32mCleaned!\033[0m"

fclean:
		@rm -f $(NAME)
		@echo "\033[0;32mCleaned!\033[0m"

re:			fclean all

.PHONY: all clean fclean re
