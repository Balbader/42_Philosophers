# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baalbade <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/02 08:16:41 by baalbade          #+#    #+#              #
#    Updated: 2023/09/02 08:16:42 by baalbade         ###   ########.fr        #
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
						ft_check_health.c \
						ft_check_vitals.c
CHECK_DINNER		:=	$(addprefix $(CHECK_DINNER_DIR), $(CHECK_DINNER_FILES))

DESTROY_DIR			:=	destroy/
DESTROY_FILES		:=	ft_destroy_mutexes.c
DESTROY				:=	$(addprefix $(DESTROY_DIR), $(DESTROY_FILES))

DINNER_DIR			:=	dinner/
DINNER_FILES		:=	\
						ft_end.c \
						ft_is_eating.c \
						ft_philo_alone.c \
						ft_print_state.c \
						ft_threader.c
DINNER				:=	$(addprefix $(DINNER_DIR), $(DINNER_FILES))

INIT_DIR			:=	init/
INIT_FILES			:=	\
						ft_init_dinner.c \
						ft_init_mutex.c \
						ft_init_philosophers.c
INIT				:=	$(addprefix $(INIT_DIR), $(INIT_FILES))

PARSING_DIR			:=	parsing/
PARSING_FILES		:=	\
						ft_check_args.c \
						ft_check_av.c
PARSING				:=	$(addprefix $(PARSING_DIR), $(PARSING_FILES))

START_DINNER_DIR	:=	start_dinner/
START_DINNER_FILES	:=	ft_start_dinner.c
START_DINNER		:=	$(addprefix $(START_DINNER_DIR), $(START_DINNER_FILES))

TIME_DIR			:=	time/
TIME_FILES			:=	\
						ft_get_time.c \
						ft_time_diff.c \
						ft_usleep.c
TIME				:=	$(addprefix $(TIME_DIR) $(TIME_FILES))

UTILS_DIR			:=	utils/
UTILS_FILES			:=	\
						ft_atoi.c \
						ft_calloc.c \
						ft_is_num.c \
						ft_itoa.c \
						ft_strcmp.c
UTILS				:=	$(addprefix $(UTILS_DIR), $(UTILS_FILES))

###############
# INGREDIENTS #
###############
SRCS_DIR			:=	./srcs/
SRCS				:=	\
						$(CHECK_DINNER) \
						$(DESTROY) \
						$(DINNER) \
						$(INIT) \
						$(PARSING) \
						$(START_DINNER) \
						$(TIME) \
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
