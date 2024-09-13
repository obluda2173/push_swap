# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erian <erian@student.42>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 16:05:21 by erian             #+#    #+#              #
#    Updated: 2024/09/11 17:32:23 by erian            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	push_swap

SRC			= 	

INCL        =	push_swap.h

OBJS		= 	$(SRC:.c=.o)

CC			= 	cc

RM			= 	rm -f

CFLAGS		= 	-Wall -Wextra -Werror -I $(INCL)


SRC += push_swap.c
SRC += list.c
SRC += checker.c
SRC += error_n_free.c
SRC += swap.c
SRC += push.c
SRC += rotate.c
SRC += reverse_rotate.c
SRC += little_sort.c
SRC += distance.c
SRC += radix.c

BLUE		=	\033[0;94m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
CYAN		=	\033[0;96m
COLOR		=	\033[0m
CLEAR		=	\033c

SUCCESS		=	@echo "$(GREEN)success !! o(≧▽≦)o$(COLOR)"
S_OBJS		=	@echo "$(BLUE)cleaning of objects completed <(￣︶￣)>$(COLOR)"
S_NAME		=	@echo "$(CYAN)full clean completed ! ヽ(・∀・)ﾉ$(COLOR)"

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./ft_printf/libftprintf.a
	$(SUCCESS)

clean:
	$(MAKE) clean -C ./ft_printf
	$(RM) $(OBJS)
	$(S_OBJS)
	
fclean: clean
	$(MAKE) fclean -C ./ft_printf
	$(RM) $(NAME)
	$(S_NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re