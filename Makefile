# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erian <erian@student.42>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 16:05:21 by erian             #+#    #+#              #
#    Updated: 2024/09/06 20:14:31 by erian            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	push_swap

SRC			= 	

OBJS		= 	$(SRC:.c=.o)

CC			= 	gcc

RM			= 	rm -f

CFLAGS		= 	-Wall -Wextra -Werror


SRC += push_swap.c
SRC += list.c
SRC += checker.c
SRC += error.c


all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./ft_printf
	$(CC) -g $(CFLAGS) -o $(NAME) $(OBJS) ./ft_printf/libftprintf.a

%.o: %.c
			$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./ft_printf
	$(RM) $(OBJS)
	$(S_OBJS)
	
fclean: clean
	$(MAKE) fclean -C ./ft_printf
	$(RM) $(NAME)
	$(S_NAME)

re:	fclean all
.PHONY:		all clean fclean re