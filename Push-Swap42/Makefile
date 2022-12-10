# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 13:00:31 by jlitaudo          #+#    #+#              #
#    Updated: 2022/12/10 23:37:59 by Teiki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################
#		VARIABLES		#
#########################

# Folders and names
NAME		:= Push-Swap2

HEAD_DIR	:=	headers/
LIST_HEAD	:=	push_swap.h
HEAD		:= $(addprefix $(HEAD_DIR), $(LIST_HEAD))

SRC_DIR		:=	src/
LIST_SRC	:=	push_swap.c swap_push_rot.c chain_list_functions.c make_sort_tab.c \
				pivot_init.c pivot_init2.c info_preparation.c display.c \
				algo_sorting.c sort_three_elem.c utils_sorting.c pre_sorting_la.c
SRC			:=	$(addprefix $(SRC_DIR), $(LIST_SRC))

LIBX_DIR	:=	Libft/
LIBX		:=	libft.a 

OBJ_DIR		:= obj/
LIST_OBJ 	:= ${LIST_SRC:.c=.o}
OBJ			:= $(addprefix $(OBJ_DIR), $(LIST_OBJ))


# Compiler options
CC 			:= cc
FLAG 		:= #-Wall -Wextra -Werror 
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
 
all:		${NAME}

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEAD)
			@mkdir -p $(@D)
			@echo "$(_GREEN)compiling: $<$(_END)"
			@${CC} ${FLAG} -I $(HEAD_DIR) -I ./Libft/headers -c $< -o $@

$(NAME): 	 $(LIBX_DIR)$(LIBX) ${OBJ} $(HEAD)
			@echo "$(_BOLD)$(_BLUE)compiling: $@$(_END)"
			@${CC} -o ${NAME} ${OBJ} $(LIBX_DIR)${LIBX} $(LIBX_DIR)libmlx.a $(FlAG_LIB) -fsanitize=address -g3
			@echo "$(_BOLD)$(_WHITE)$@ SUCCESSFULLY CREATED$(_END)"

$(LIBX_DIR)$(LIBX) :
			@echo "$(_BOLD)$(_PURPLE) Compilation of $(LIBX) begin $(_END)"
			@make -C $(LIBX_DIR)
			@echo

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

fcleanall:	clean
			@make fclean -C $(LIBX_DIR)
			@echo
			@rm -f ${NAME}
			@echo "$(_RED)$(_BOLD)$(NAME) deleted$(_END)"

re: 		fclean all

reall:		fcleanall all

.PHONY:		all clean fclean fcleanall re reall
