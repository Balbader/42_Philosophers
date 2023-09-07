# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 12:37:27 by tmalless          #+#    #+#              #
#    Updated: 2023/03/30 15:34:31 by tmalless         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = src/main.c src/check_args.c src/clean.c src/init.c \
src/ft_atoi.c src/ft_itoa.c src/ft_calloc.c \
src/ft_strcmp.c src/launcher.c src/sim_utils.c

PATH_OBJS = objs/

DIR_OBJS = objs

OBJECT = $(SRCS:.c=.o)

#$(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

#$(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECT)
	$(CC) -pthread $(CFLAGS) -o $(NAME) $(OBJECT)

clean : 
	rm -f $(OBJECT)

fclean : clean
	rm -f philo

re : fclean all

.PHONY: all clean fclean re