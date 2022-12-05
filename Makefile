# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 13:20:43 by rsiqueir          #+#    #+#              #
#    Updated: 2022/11/14 01:30:57 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
# -Wall -Werror -Wextra
CC = cc
CFLAGS = -lreadline
RM = rm -f

SRCS =	src/main.c	\
		src/utils.c	\
		src/ft_split.c \
		src/libft.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) -I./include -c $< -o $@

$(NAME): $(OBJS)
	$(CC)  $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME) 

re: fclean all

.PHONY:	all clean fclean re