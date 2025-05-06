# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lposse <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 18:11:21 by lposse            #+#    #+#              #
#    Updated: 2025/05/06 20:05:51 by lposse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = Libft
LIBFT = Libft/libft.a 

SRCS = push_swap.c push_swap2.c push_swap3.c push_swap_main.c \
       push_swap_operations_pushswap.c push_swap_operations_reverserotate.c \
       push_swap_operations_rotate.c push_swap_utils.c push_swap_utils2.c push_swap_utils3.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "Compilando libft.a..."
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): Makefile $(OBJS)
	@echo "Creando pushswap..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -I $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
