# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 13:00:31 by jlitaudo          #+#    #+#              #
#    Updated: 2022/12/19 13:59:17 by jlitaudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################
#		VARIABLES		#
#########################

# Folders and names
NAME		:= push_swap

HEAD_DIR	:=	headers/
LIST_HEAD	:=	push_swap.h\
				checker.h
HEAD		:= $(addprefix $(HEAD_DIR), $(LIST_HEAD))

LIST_SORT	:=	adding_information_to_list.c\
				algo_sorting.c\
				check_and_pull_back.c\
				counting_elem_low_piv.c\
				init_sorting_la.c\
				init_sorting_lb.c\
				no_more_piv.c\
				pivot_init.c\
				pivot_init2.c\
				pivot_la.c\
				pivot_lb.c\
				re_indexing.c\
				sorting_pilot.c \
				split_categ_sorting.c\
				split_categ.c\

SORT_DIR	:=	sorting/
SORTING		:=	$(addprefix $(SORT_DIR), $(LIST_SORT))

LIST_TOOLS	:=	chain_list_functions.c\
				chain_list_functions2.c\
				display.c\
				make_sort_tab.c\
				make_tab_piv.c\
				rotate.c\
				swap_push.c\

TOOLS_DIR	:=	tools/
TOOLS		:=	$(addprefix $(TOOLS_DIR), $(LIST_TOOLS))

LIST_CHECK	:=	checking_input.c\
				checking_input_final.c\

CHECK_DIR	:=	checking/
CHECKING	:=	$(addprefix $(CHECK_DIR), $(LIST_CHECK))

LIST_BONUS	:=	do_instruction.c\
				double_action_bonus.c\
				execute_command.c\
				main_checker.c\
				sorting_pilot_bonus.c\

BONUS_DIR	:= bonus/
BONUS		:= $(addprefix $(BONUS_DIR), $(LIST_BONUS))

LIST_SRC	:=	main.c\
				$(CHECKING)\
				$(TOOLS)\
				$(SORTING)\

LIST_SRC_B	:=	$(BONUS)\
				$(CHECKING)\
				$(TOOLS)\
				$(SORTING)\

SRC_DIR		:=	src/
SRC			:=	$(addprefix $(SRC_DIR), $(LIST_SRC))

LIBX_DIR	:=	Libft/
LIBX		:=	libft.a 

OBJ_DIR		:= obj/
LIST_OBJ 	:= ${LIST_SRC:.c=.o}
OBJ			:= $(addprefix $(OBJ_DIR), $(LIST_OBJ))

LIST_OBJ_B	:= ${LIST_SRC_B:.c=.o}
OBJ_BONUS	:= $(addprefix $(OBJ_DIR), $(LIST_OBJ_B))

# Compiler options
CC 			:= cc
FLAG 		:= -Wall -Wextra -Werror 
FLAG_LIB	:= -I ./Libft/headers -L ./Libft/libft.a
NORM		:= norminette -R -CheckDefine

# define standard colors
_END		:=	\x1b[0m
_BOLD		:=	\x1b[1m
_UNDER		:=	\x1b[4m
_REV		:=	\x1b[7m
_GREY		:=	\x1b[30m
_RED		:=	\x1b[31m
_GREEN		:=	\x1b[32m
_YELLOW		:=	\x1b[33m
_BLUE		:=	\x1b[34m
_PURPLE		:=	\x1b[35m
_CYAN		:=	\x1b[36m
_WHITE		:=	\x1b[37m

#########################
# 		RULES			#
#########################
 
all:		lib ${NAME} checker

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEAD)
			@mkdir -p $(@D)
			@echo "$(_GREEN)compiling: $<$(_END)"
			@${CC} ${FLAG} -I $(HEAD_DIR) -I ./Libft/headers -c $< -o $@

$(NAME): 	 $(LIBX_DIR)$(LIBX) ${OBJ} $(HEAD)
			@echo "$(_BOLD)$(_BLUE)compiling: $@$(_END)"
			@${CC} -o ${NAME} ${OBJ} $(LIBX_DIR)${LIBX} $(FlAG_LIB) 
			@echo "$(_BOLD)$(_WHITE)$@ SUCCESSFULLY CREATED$(_END)"

lib:
			@echo "$(_BOLD)$(_PURPLE) Compilation of $(LIBX) begin $(_END)"
			@make -C $(LIBX_DIR)
			@echo

bonus:		checker

checker:	$(LIBX_DIR)$(LIBX) $(OBJ_BONUS) $(HEAD)
			@echo "$(_BOLD)$(_BLUE)compiling: $@$(_END)"
			@${CC} -o checker ${OBJ_BONUS} $(LIBX_DIR)${LIBX} $(FlAG_LIB) 
			@echo "$(_BOLD)$(_WHITE)$@ SUCCESSFULLY CREATED$(_END)"

norm:		$(NORM) $(SRC)

push:		$(NAME)
			@./$(NAME) 0 5 454 2135 1235 45578 4523
clean:
			@make clean -C $(LIBX_DIR)
			@rm -rf ${OBJ_DIR}
			@echo "$(_RED)directory $(OBJ_DIR) deleted$(_END)"

fclean: 	clean
			@rm -f ${NAME}
			@echo "$(_RED)$(_BOLD)$(NAME) deleted$(_END)"

fcleanb:	clean
			@rm -f checker
			@echo "$(_RED)$(_BOLD)$(NAME) deleted$(_END)"

fcleanall:	clean
			@make fclean -C $(LIBX_DIR)
			@echo
			@rm -f ${NAME} checker
			@echo "$(_RED)$(_BOLD)$(NAME) deleted$(_END)"

re: 		fclean $(NAME)

reall:		fcleanall all

.PHONY:		all clean fclean fcleanall re reall
