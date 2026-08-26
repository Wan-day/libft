# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/24 19:34:31 by dboldino          #+#    #+#              #
#    Updated: 2026/08/26 12:06:29 by dboldino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

TARGET = test
SRCS = tester.c
LIBFT = libft.a

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(TARGET)

clean:
	$(RM) $(TARGET)

fclean: clean
	$(RM) $(LIBFT) libft.h

re: clean all

.PHONY: all clean re
