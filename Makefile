# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apodader <apodader@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/23 13:55:20 by apodader          #+#    #+#              #
#    Updated: 2024/09/06 20:37:43 by apodader         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

SRC_CLIENT = src/client.c
SRC_SERVER = src/server.c

OBJ_DIR = obj
OBJS_CLIENT = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_CLIENT:.c=.o)))
OBJS_SERVER = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_SERVER:.c=.o)))
DEPS_CLIENT = $(OBJS_CLIENT:.o=.d)
DEPS_SERVER = $(OBJS_SERVER:.o=.d)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -MMD
RM = rm -rf

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --silent

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	$(RM) $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

-include $(DEPS_CLIENT) $(DEPS_SERVER)

.PHONY: all clean fclean re
