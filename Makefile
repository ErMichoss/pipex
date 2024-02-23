# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 15:45:13 by nicgonza          #+#    #+#              #
#    Updated: 2024/02/23 10:32:15 by nicgonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

LIB = ar rcs

SRCS = src/main.c \
	   src/ft_split.c \
	   src/ft_strjoin.c \
	   src/ft_exc_cmd.c \
	   src/ft_strcmp.c \
	   src/free.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJS)

re: all clean

.PHONY: all clean fclean re
