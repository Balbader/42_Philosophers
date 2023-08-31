# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 09:40:00 by baalbade          #+#    #+#              #
#    Updated: 2023/08/26 09:40:08 by baalbade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########
# NAME #
########
NAME				:=	philo

##############
# SRCS FILES #
##############
CHECK_DINNER_DIR	:=	check_dinner/
CHECK_DINNER_FILES	:=	\
						ft_check_meal_count.c \
						ft_check_philosopher.c
CHECK_DINNER		:= 	$(addprefix $(CHECK_DINNER_DIR), $(CHECK_DINNER_FILES))

DINNER_DIR			:=	dinner/
DINNER_FILES		:=	\
						ft_dinner.c \
						ft_eat.c \
						ft_setup_dinner.c
DINNER				:=	$(addprefix $(DINNER_DIR), $(DINNER_FILES))

INIT_DIR			:=	init/
INIT_FILES			:=	\
						ft_init_mutexes_arr.c \
						ft_init_mutexes.c \
						ft_init_philosophers.c \
						ft_setup_philosophers.c
INIT				:=	$(addprefix $(INIT_DIR), $(INIT_FILES))

PARSING_DIR			:=	parsing/
PARSING_FILES		:=	\
						ft_parse_config.c \
						ft_parse_times.c
PARSING				:=	$(addprefix $(PARSING_DIR), $(PARSING_FILES))

START_DINNER_DIR	:=	start_dinner/
START_DINNER_FILES	:=	\
						ft_init_threads.c \
						ft_init_threads_monitoring.c \
						ft_start_dinner.c \
						ft_start_threads.c
START_DINNER		:=	$(addprefix $(START_DINNER_DIR), $(START_DINNER_FILES))

THINK_DIR			:=	think/
THINK_FILES			:=	ft_is_thinking.c
THINK				:=	$(addprefix $(THINK_DIR), $(THINK_FILES))

UTILS_DIR			:=	utils/
UTILS_FILES			:=	\
						ft_atoi_long.c \
						ft_clean_exit.c \
						ft_clean_mutexes.c \
						ft_get_time.c \
						ft_is_dead.c \
						ft_memdel.c \
						ft_print_err.c \
						ft_putstr_fd.c \
						ft_strcmp.c \
						ft_usleep.c
UTILS				:=	$(addprefix $(UTILS_DIR), $(UTILS_FILES))

###############
# INGREDIENTS #
###############

SRCS_DIR			:=	./srcs/
SRCS				:=	\
						$(CHECK_DINNER) \
						$(DINNER) \
						$(INIT) \
						$(PARSING) \
						$(START_DINNER) \
						$(THINK) \
						$(UTILS) \
						main.c
SRCS				:=	$(SRCS:%=$(SRCS_DIR)/%)

BUILD_DIR			:=	.build
OBJS				:=	$(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS				:=	$(OBJS:.o=.d)

CC					:=	cc
# CFLAGS				:=	-Wall -Wextra -Werror -g3 -fsanitize=thread
CFLAGS				:=	-Wall -Wextra -Werror -g3
RM					:=	rm -r -f
MAKEFLAGS			+=	--no-print-directory
DIR_DUP				=	mkdir -p $(@D)

##########
# COLORS #
##########
RED					:=	\033[0;31m
GREEN				:=	\033[0;32m
YELLOW				:=	\033[0;33m
RESET				:=	\033[0m

###########
# RECIPES #
###########
all: $(NAME)

$(NAME): $(OBJS)
	@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) -pthread -o $(NAME)
	@echo "[" "$(GREEN)OK$(RESET)" "] | $(NAME) ready!"

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS)  -c -o $@ $<

-include $(DEPS)

clean:
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing object files...$(RESET)"
	@$(RM) $(BUILD_DIR) $(OBJS) $(DEPS)
	@echo "[" "$(GREEN)OK$(RESET)" "] | Object files removed."

fclean: clean
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing binary files...$(RESET)"
	@$(RM) $(NAME)
	@echo "[" "$(GREEN)OK$(RESET)" "] | Object files removed."

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
