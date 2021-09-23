# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 17:31:05 by vcastilh          #+#    #+#              #
#    Updated: 2021/09/22 17:54:09 by vcastilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl
CC = clang
CFLAGS = -Wall -Wextra -Werror -I.
SRC = get_next_line.c\
	  get_next_line_utils.c\

BUFF_SIZE = 20

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -D BUFF_SIZE=$(BUFF_SIZE) $(SRC) 

clean:
	rm -f $(NAME)

re: clean all

.PHONY: clean all $(NAME)

