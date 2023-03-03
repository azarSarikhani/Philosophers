# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#              #
#    Updated: 2023/03/03 12:05:31 by asarikha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC_PATH	= src/
SRC = main.c validate.c
SRCS		= $(addprefix $(SRC_PATH),$(SRC))

OBJ_PATH	= obj/
OBJ = $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

INCLUDE = -I ./includes/

CC := cc
CFLAGS := -Wall -Wextra -Werror

.PHONY: all  clean fclean re

all: $(NAME)

print:
	@echo $(SRCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJS): $(OBJ_PATH)%.o:$(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ_PATH) $(OBJS)
	echo "Compiling philo"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)
	echo "Philo ready."

clean:
	@rm -rf $(OBJ_PATH)
	@echo "Objects removed"

fclean: clean
	@rm -f $(NAME)
	@echo "executable removed"

.PHONY: re
re: fclean all