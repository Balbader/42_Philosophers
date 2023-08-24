################################################################################
#                                    CONFIG                                    #
################################################################################

NAME		= philo
AUTHOR		= jmazoyer

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= $(foreach path, $(INC_PATH), -I$(path))
CPPFLAGS	+= -MMD
LDLIBS		= $(foreach lib, $(LIB_NAME), -l$(lib))
RM			= rm -fr

V			= 0
N			= 0
S			= 0
F			= 1

################################################################################
#                               SRCS - INCLUDES                                #
################################################################################

LIB_NAME		= pthread

INC_PATH		= includes

SRC_PATH		= srcs
SRC_NAME		=	main.c			\
					utils.c			\
					parsing.c		\
					init.c			\
					launch_diner.c	\
					diner.c			\
					monitor_diner.c	\
					speak.c

OBJ_PATH		= objs
OBJ				= $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

DEP				= $(OBJ:.o=.d)

VPATH			= $(SRC_PATH)

################################################################################
#                          COLORS - STRINGS - SYMBOLS                          #
################################################################################

RED		  = \033[0;31m
B_RED	  = \033[0;91m
GREEN	  = \033[0;32m
B_GREEN	  = \033[0;92m
YELLOW	  = \033[0;33m
B_YELLOW  = \033[0;93m
BLUE	  = \033[0;34m
B_BLUE	  = \033[0;94m
MAGENTA	  = \033[0;35m
B_MAGENTA = \033[0;95m
CYAN	  = \033[0;36m
B_CYAN	  = \033[0;96m
GRAY	  = \033[0;90m
B_GRAY	  = \033[0;37m
NO_COLOR  = \033[m

MKDIR	  = Creating directory
COMPIL	  = Compiling & assembling
FLAGS	  = Compiler flags
LINK 	  = Linking

################################################################################
#                                  FUNCTIONS                                   #
################################################################################

ifeq ($(detected_OS),Darwin) 
	RUN_CMD = script -q "$(@F).log" $1 > /dev/null; \
				RESULT=$$?
else ifeq ($(detected_OS),Linux)
	RUN_CMD = script -q -e -c "$(1)" "$(@F).log" > /dev/null; \
				RESULT=$$?; \
				sed -i '1d' "$(@F).log"; \
				sed -i "$$(($$(wc -l < "$(@F).log")-1)),\$$d" "$(@F).log"
else
	RUN_CMD = $(1) 2> "$(@F).log"; \
				RESULT=$$?
endif

define run
if [ $(S) -eq 1 ]; then \
	:; \
elif [ $(N) -eq 1 ]; then \
	printf "%b\n" "$(1)"; \
elif [ $(V) -eq 1 ]; then \
	printf "%b\n" "$(GRAY)$(1)"; \
elif ( echo "$(@F)" | grep -q '\.o' ) && [ $(F) -eq 1 ]; then \
	printf "%-30b%-35b\n" "$(BLUE)$(FLAGS)" "$(GRAY)$(CFLAGS)$(NO_COLOR)"; \
fi
if [ $(S) -eq 1 ]; then \
	:; \
elif ( echo "$(2)" | grep -q 'clean' ) && [ $(N) -eq 0 ]; then \
	printf "%-58b" "$(BLUE)$(2)$(NO_COLOR)"; \
elif [ $(N) -eq 0 ]; then \
	printf "%-30b%-35b" "$(BLUE)$(2)" "$(3)$(@F)$(NO_COLOR)"; \
fi
if ( echo "$(2)" | grep -q 'clean' ); then \
	$(1); \
	RESULT=$$?; \
else \
	$(RUN_CMD); \
fi ; \
if [ $(S) -eq 1 ]; then \
	:; \
elif [ $(N) -eq 0 -a $$RESULT -ne 0 ]; then \
	printf "%b\n" "$(RED)[KO]"; \
elif [ $(N) -eq 0 -a -s "$(@F).log" ]; then \
	printf "%b\n" "$(YELLOW)[WARN]"; \
elif [ $(N) -eq 0 ]; then  \
	printf "%b\n" "$(GREEN)[OK]"; \
fi; \
printf "%b" "$(NO_COLOR)"; \
cat "$(@F).log" 2> /dev/null; \
rm -f "$(@F).log"; \
exit $$RESULT
endef

################################################################################
#                                    RULES                                     #
################################################################################

all: $(NAME)

$(NAME): $(OBJ)
	@$(call run,$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@ \
		,$(LINK),$(B_GREEN))
	$(eval F=1)

$(OBJ_PATH)/%.o: %.c | $(OBJ_PATH)
	@$(call run,$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@,$(COMPIL),$(B_CYAN))
	$(eval F=0)

$(OBJ_PATH):
	@$(call run,mkdir -p $@,$(MKDIR),$(B_BLUE))

clean: header
	@$(call run,$(RM) $(OBJ_PATH) *.log,clean)

fclean: clean
	@$(call run,$(RM) $(NAME) $(BONUS_NAME),fclean)

re: fclean all

-include $(DEP)

.PHONY: all header clean fclean re
