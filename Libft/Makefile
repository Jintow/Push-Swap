# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 09:23:38 by jlitaudo          #+#    #+#              #
#    Updated: 2022/12/15 01:01:30 by Teiki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################
#		MAIN			#
#########################

# Folders and names

NAME		:=	libft.a

HEAD_DIR	:=	headers/
LIST_HEAD	:=	libft.h ft_printf.h
HEAD		:=	$(addprefix $(HEAD_DIR), $(LIST_HEAD))

#########################
#		SOURCE FILES	#
#########################

ASCII_SRC	:= 	ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\

ASCII_DIR	:=	ascii_func/
ASCII		:=	$(addprefix $(ASCII_DIR), $(ASCII_SRC))


LIST_SRC	:=  ft_lst_addback.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c\
				ft_lstsize.c\
            	ft_lstadd_front.c\
            	ft_lstdelone.c\
            	ft_lstlast.c\
            	ft_lstnew.c\

LIST_DIR	:=	lst_func/
LIST		:=	$(addprefix $(LIST_DIR), $(LIST_SRC))

PRINT_SRC	:=	ft_printf.c\
				ft_putchar_fd.c\
                ft_putendl_fd.c\
                ft_putnbr_fd.c\
                ft_putstr_fd.c\
				ft_putchar_fd.c\
			    ft_putnbr_fd.c\
				print_pointer.c\
				print_putnbr.c\
				print_putstr.c\
				print_putchar.c\
				print_putnbr_hex_low.c\
				print_putnbr_hex_cap.c\
				print_putnbr_unsigned.c\

PRINT_DIR	:=	print_func/
PRINT		:=	$(addprefix $(PRINT_DIR), $(PRINT_SRC))

STR_SRC		:=	ft_calloc.c\
				ft_split.c\
				ft_count_word.c\
				ft_free_tab.c\
				size_tab.c\
				ft_atoi.c\
				ft_strchr.c\
				ft_striteri.c\
				ft_strlcat.c\
				ft_strlen.c\
				ft_strcmp.c\
				ft_strncmp.c\
				ft_strrchr.c\
				ft_substr.c\
				ft_toupper.c\
                ft_itoa.c\
                ft_strdup.c\
				ft_strndup.c\
                ft_strjoin.c\
				ft_strjoin_free.c\
				ft_strnjoin.c\
                ft_strlcpy.c\
                ft_strmapi.c\
                ft_strnstr.c\
                ft_strtrim.c\
				ft_tolower.c\
				ft_memchr.c\
                ft_memcmp.c\
                ft_memcpy.c\
                ft_memmove.c\
                ft_memset.c\
				ft_bzero.c\
				ft_is_inside.c\
				ft_valid_format.c\

STR_DIR		:=	str_func/
STR			:=	$(addprefix $(STR_DIR), $(STR_SRC))

#fonctions de manipulation de nombres
NB_SRC		:=	ft_intdup.c\

NB_DIR		:=	int_func/
NB			:=	$(addprefix $(NB_DIR), $(NB_SRC))

SRC_DIR		:=	src/
SRC_FILES	:=	$(ASCII) $(LIST) $(PRINT) $(STR) $(NB)
SRC			:=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR		:=	obj/
LIST_OBJ 	:=	${SRC_FILES:.c=.o}
OBJ			:= $(addprefix $(OBJ_DIR), $(LIST_OBJ))

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

# Compiler options
CC			:= gcc
Clib		:= ar rc
RANLIB		:= ranlib
FLAG 		:= -Wall -Wextra -Werror
NORM		:= norminette -R -CheckDefine

#########################
# 		RULES			#
#########################

all:			${NAME} 

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(HEAD)
				@mkdir -p $(@D)
				@echo "$(_GREEN)compiling: $<$(_END)"
				@${CC} ${FLAG} -I $(HEAD_DIR) -c $< -o $@

$(NAME):		${OBJ} $(HEAD)
				@echo "$(_BOLD)$(_BLUE)compiling: $@$(_END)"
				@${Clib} ${NAME} ${OBJ}
				@${RANLIB} ${NAME}
				@echo "$(_BOLD)$(_WHITE)$@ SUCCESSFULLY CREATED$(_END)"

echo:			
				@echo $(OBJ)
				@echo $(SRC)
# @echo $(STR)
# @echo $(LIST)
# @echo $(PRINT)
# @echo $(ASCII)

clean:
				@rm -rf ${OBJ_DIR}
				@echo "$(_RED)directory Libft/$(OBJ_DIR) deleted$(_END)"

fclean: 		clean
				@rm -f ${NAME}
				@echo "$(_RED)$(_BOLD)$(NAME) deleted$(_END)"

re: 			fclean all

.PHONY:			all clean fclean re bonus
