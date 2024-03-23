# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 15:45:13 by nicgonza          #+#    #+#              #
#    Updated: 2024/03/08 12:43:19 by nicgonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

BNS_NAME = pipex_bonus

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

BNS = bonus/free.c \
	  bonus/ft_cmd_exec.c \
	  bonus/ft_files.c \
	  bonus/ft_here_doc.c \
	  bonus/ft_split.c \
	  bonus/ft_strcmp.c \
	  bonus/get_next_line.c \
	  bonus/get_next_line_utils.c \
	  bonus/main.c

OBJS = $(SRCS:.c=.o)

OBJS_BNS = $(BNS:.c=.o)

all: $(NAME)

bonus: $(BNS_NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(BNS_NAME): $(OBJS_BNS)
	$(CC) $(CFLAGS) -o $(BNS_NAME) $(OBJS_BNS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BNS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJS)
	$(RM) $(OBJS_BNS)
	$(RM) $(BNS_NAME)

re: fclean all

.PHONY: all clean fclean re
