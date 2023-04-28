# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 16:59:22 by changhyl          #+#    #+#              #
#    Updated: 2023/04/29 04:16:22 by changhyl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRCS1 = ft_putnbr_fd.c server.c
SRCS2 = ft_atoi.c client.c
OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)

all:	$(NAME)

$(NAME):	$(SERVER) $(CLIENT)

$(SERVER):	$(OBJS1)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT):	$(OBJS2)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS1)
	rm -f $(OBJS2)

fclean:	clean
	rm -f $(SERVER)
	rm -f $(CLIENT)

re:
	$(MAKE)	fclean
	$(MAKE)	all

.PHONY: all clean fclean re
