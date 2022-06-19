NAME		= philo

# -g -fsanitize=address

CC			= gcc
CFLAGS		= -g -Wall -Werror -Wextra -fsanitize=address

all:		$(NAME)

SRCS		= main.c \
			# src/philosophers.c \

INCS		= ./inc/philosophers.h

OBJS		= $(SRCS:.c=.o)

$(NAME):		$(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "\033[0;32mDone!\n\033[0m"

clean:
		rm -f $(OBJS)

fclean:
		rm -f $(NAME)
		@echo "\033[0;32mClean!\n\033[0m"

re:			fclean all

.PHONY: all clean fclean re
