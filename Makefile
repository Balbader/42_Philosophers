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
CHECK_DINNER_FILES	:=
CHECK_DINNER		:= 	$(addprefix $(CHECK_DINNER_DIR), $(CHECK_DINNER_FILES))

DINNER_DIR			:=	dinner/
DINNER_FILES		:=	\
						ft_dinner.c \
						ft_eat.c \
						ft_setup_denner.c
DINNER				:=	$(addprefix $(DINNER_DIR), $(DINNER_FILES))

INIT_DIR			:=	init/
INIT_FILES			:=	\
						ft_init_mutexes_arr.c \
						ft_init_mutexes.c \
						ft_init_philosophers.c \
						ft_setup_philosophers.c
INIT				:=	$(addprefix $(INIT_DIR), $(INIT_FILES))

THINK_DIR			:=	think/
THINK_FILES			:=	ft_is_thinking.c
THINK				:=	$(addprefix $(THINK_DIR), $(THINK_FILES))

START_DINNER_DIR	:=	start_dinner/
START_DINNER_FILES	:=	\
						ft_init_threads.c \
						ft_init_threads_monitoring.c \
						ft_start_dinner.c \
						ft_start_threads
START_DINNER		:=	$(addprefix $(START_DINNER_DIR), $(START_DINNER_FILES))

UTILS_DIR			:=	utils/
UTILS_FILES			:=	\
						ft_is_dead.c \
						ft_strcmp.c \
UTILS				:=	$(addprefix $(UTILS_DIR), $(UTILS_FILES))

###############
# INGREDIENTS #
###############
INC_DIR				:=	./inc/

SRCS_DIR			:=	./srcs/
SRCS_FILES			:=	\
						$(check_dinner) \
						$(dinner) \
						$(init) \
						$(think) \
						$(start) \
						$(utils) \
						main.c
SRCS				:=	$(SRCS:%=$(SRCS_DIR)/%)

BUILD_DIR			:=	.build
OBJS				:=	$(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS				:=	$(OBJS:.o=.d)

CC					:=	cc
CFLAGS				:=	-Wall -Wextra -Werror -g3
IFLAGS				:=	$(addprefix -I, $(INC_DIR))

RM					:=	rm -r -f
DIR_DUP				:=	mkdir -p $(dir $@)

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
	@$(CC) $(CFLAGS) -o $@
	@echo "[" "$(GREEN)OK$(RESET)" "] | $(NAME) ready!"

$(BUILD_DIR)/%.o: $SRCS_DIR/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

-include $(DEPS)

clean:
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing object files...$(RESET)"
	@$(RM) $(BUILD_DIR) $(DEPS)
	@echo "[" "$(GREEN)OK$(RESET)" "] | Object files removed."

fclean:
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing binary files...$(RESET)"
	@$(RM) $(NAME)
	@echo "[" "$(GREEN)OK$(RESET)" "] | binary files removed."

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
