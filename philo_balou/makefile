NAME=philo

SRC_FILES=	main.c\
			ft_init.c\
			gettime.c\
			threads.c\
			sleep.c\
			eat.c\
			eat_even.c\
			eat_odd.c\
			is_dead.c\
			ft_atoi.c\
			ft_putstr_fd.c\
			ft_printf.c\
			ft_printf_utils.c\
			ft_printf_ter.c\
			ft_isdigit.c\
			mutex_init.c\
			free_all.c

SRC_DIR=./src/
INC_DIR=./includes/

LD_FLAGS= -lpthread

SRC=$(addprefix ${SRC_DIR}, ${SRC_FILES})
INC=$(addprefix ${INC_DIR}, ${INC_FILES})
OBJ=${SRC:.c=.o}

CC=cc
CFLAGS=-g3 -Wall -Wextra -Werror
RM=rm -rf

all: ${NAME}

${NAME}: ${OBJ} makefile
	${CC} ${CFLAGS} -o ${NAME} ${OBJ} ${LD_FLAGS}

.c.o:
	${CC} ${CFLAGS} -I${INC_DIR} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re reclean

norm:
	norminette $(SRC) $(INC_DIR) $(LIBFT_PATH) | awk '{if ($$NF == "OK!") { print "\033[0;92m"$$0"\033[0m" } else if ($$NF == "Error!") { print "\033[0;91m"$$0"\033[0m" } else { print }}'