# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 15:23:08 by ajordan-          #+#    #+#              #
#    Updated: 2023/02/05 16:59:23 by jcrescen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/bash

NAME		= client
NAMESV		= server
NAMEBC		= client_bonus
NAMEBS		= server_bonus
LIBFT		= libft
INC			= inc
HEADER		= -I inc
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
FSANITIZE	= -fsanitize=address -g3
RM			= rm -f
ECHO		= echo -e

DEF_COLOR	=	\033[0;39m
GREEN		=	\033[1;92m

SRCCL_FILES	=	client
SRCSV_FILES	=	server
SRCBC_FILES	=	client_bonus
SRCBS_FILES	=	server_bonus

SRCCL 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCCL_FILES)))
OBJCL 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCCL_FILES)))

SRCSV 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCSV_FILES)))
OBJSV 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCSV_FILES)))

SRCBC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCBC_FILES)))
OBJBC 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCBC_FILES)))

SRCBS 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCBS_FILES)))
OBJBS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCBS_FILES)))


OBJF		=	.cache_exists

start:
			@make -C $(LIBFT)
			@cp $(LIBFT)/libft.a .
			@$(ECHO) -n "Dependencies:"
			@make all

all:		$(NAME) $(NAMESV)

$(NAME):	$(OBJCL) $(OBJF)
			@$(CC) $(FLAGS) $(OBJCL) $(HEADER) libft.a -o $(NAME)

$(NAMESV):	$(OBJSV) $(OBJF)
			@$(ECHO) -n "$(GREEN)100%$(DEF_COLOR)\n"
			@$(ECHO) -n "minitalk:"
			@$(CC) $(FLAGS) $(OBJSV) $(HEADER) libft.a -o $(NAMESV)
			@$(ECHO) "$(GREEN)Created ✔️$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJF)
			@$(CC) $(FLAGS) $(HEADER) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@touch $(OBJF)

bonus:
			@make -C $(LIBFT)
			@cp $(LIBFT)/libft.a .
			@$(ECHO) -n "Dependencies: $(DEF_COLOR)"
			@make allbonus

allbonus:		$(NAMEBC) $(NAMEBS)

$(NAMEBC):	$(OBJBC) $(OBJF)
			@$(CC) $(FLAGS) $(OBJBC) $(HEADER) libft.a -o $(NAMEBC)

$(NAMEBS):	$(OBJBS) $(OBJF)
			@$(ECHO) -n "$(GREEN)100%$(DEF_COLOR)\n"
			@$(ECHO) -n "Minitalk_Bonus:$(DEF_COLOR)"
			@$(CC) $(FLAGS) $(OBJBS) $(HEADER) libft.a -o $(NAMEBS)
			@$(ECHO) "$(GREEN)Created ✔️$(DEF_COLOR)"

clean:
			@$(RM) -r $(OBJ_DIR)
			@$(RM) $(OBJF)
			@make clean -C $(LIBFT)
			@$(ECHO) -n "Minitalk: objc. files$(DEF_COLOR)$(GREEN) Cleaned ✔️$(DEF_COLOR)\n"

fclean:		clean
			@$(RM) $(NAME) $(NAMESV) $(NAMEBC) $(NAMEBS)
			@$(RM) $(LIBFT)/libft.a
			@$(RM) libft.a
			@find . -name ".DS_Store" -delete
			@$(ECHO) -n "Minitalk: exec. files$(DEF_COLOR)$(GREEN) Cleaned ✔️$(DEF_COLOR)\n"


re:			fclean all
			@$(ECHO) -n "$(GREEN)Cleaned and rebuilt ✔️$(DEF_COLOR)\n"

.PHONY:		start all clean fclean re bonus