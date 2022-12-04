# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 13:00:31 by jlitaudo          #+#    #+#              #
#    Updated: 2022/12/04 20:25:43 by Teiki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################
#		VARIABLES		#
#########################

# Folders and names
NAME		:= Push-Swap

HEAD_DIR	:=	headers/
LIST_HEAD	:=	push_swap.h ft_printf.h
HEAD		:= $(addprefix $(HEAD_DIR), $(LIST_HEAD))

SRC_DIR		:=	src/
LIST_SRC	:=	push_swap.c chain_list_functions.c swap_push_rot.c \
				\
				utils/ft_printf.c utils/print_pointer.c utils/print_putchar.c utils/print_putnbr.c\
				utils/print_putnbr_hex_cap.c utils/print_putnbr_hex_low.c utils/print_putnbr_unsigned.c\
				utils/print_putstr.c utils/ft_strlen.c  utils/ft_strcmp.c utils/ft_atoi_base.c utils/ft_strupcase.c \
				utils/ft_itoa.c utils/ft_atof.c
SRC			:= $(addprefix $(SRC_DIR), $(LIST_SRC))

LIBX_DIR	:=
LIBX		:=

OBJ_DIR		:= obj/
LIST_OBJ 	:= ${LIST_SRC:.c=.o}
OBJ			:= $(addprefix $(OBJ_DIR), $(LIST_OBJ))


# Compiler options
CC 			:= cc
FLAG 		:= #-Wall -Wextra -Werror
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
			@${CC} ${FLAG} -I $(HEAD_DIR) -c $< -o $@

$(NAME): 	${OBJ} $(LIBX_DIR)$(LIBX) $(HEAD)
			@echo "$(_BOLD)$(_BLUE)compiling: $@$(_END)"
			@${CC} -o ${NAME} ${OBJ} $(LIBX_DIR)${LIBX}  -framework CoreFoundation
			@echo "$(_BOLD)$(_WHITE)$@ SUCCESFULLY CREATED$(_END)"

$(LIBX_DIR)$(LIBX) :
			@echo "$(_BOLD)$(_PURPLE)compiling: $@$(_END)"
			@make -C $(LIBX_DIR)

norm:		$(NORM) $(SRC)

push:		$(NAME)
			@./$(NAME) 0 5 454 2135 1235 45578 4523
clean:
			rm -rf ${OBJ_DIR}

fclean: 	clean
			rm -f ${NAME}
#make clean -C $(LIBX_DIR)

re: 		fclean all

.PHONY:		all clean fclean re bonus
