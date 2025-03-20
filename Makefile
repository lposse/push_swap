# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lposse <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 18:11:21 by lposse            #+#    #+#              #
#    Updated: 2025/03/19 19:07:11 by lposse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = Libft
LIBFT_OBJS = Libft/objs/ft_atoi.o Libft/objs/ft_bzero.o Libft/objs/ft_calloc.o Libft/objs/ft_isalnum.o Libft/objs/ft_isascii.o Libft/objs/ft_isalpha.o Libft/objs/ft_isdigit.o Libft/objs/ft_isprint.o Libft/objs/ft_itoa.o Libft/objs/ft_memchr.o Libft/objs/ft_memcmp.o Libft/objs/ft_memcpy.o Libft/objs/ft_memmove.o Libft/objs/ft_memset.o Libft/objs/ft_putchar_fd.o Libft/objs/ft_putendl_fd.o Libft/objs/ft_putnbr_fd.o Libft/objs/ft_putstr_fd.o Libft/objs/ft_split.o Libft/objs/ft_strchr.o Libft/objs/ft_strdup.o Libft/objs/ft_striteri.o Libft/objs/ft_strjoin.o Libft/objs/ft_strlcat.o Libft/objs/ft_strlcpy.o Libft/objs/ft_strlen.o Libft/objs/ft_strmapi.o Libft/objs/ft_strncmp.o Libft/objs/ft_strnstr.o Libft/objs/ft_strrchr.o Libft/objs/ft_strtrim.o Libft/objs/ft_substr.o Libft/objs/ft_tolower.o Libft/objs/ft_toupper.o Libft/objs/ft_lstadd_front_bonus.o Libft/objs/ft_lstlast_bonus.o Libft/objs/ft_lstnew_bonus.o Libft/objs/ft_lstsize_bonus.o Libft/objs/ft_lstadd_back_bonus.o Libft/objs/ft_lstdelone_bonus.o Libft/objs/ft_lstclear_bonus.o Libft/objs/ft_lstiter_bonus.o Libft/objs/ft_lstmap_bonus.o Libft/objs/basic_functions.o Libft/objs/ft_printf_general.o Libft/objs/ft_printf_functions.o
 
NAME = libft_bonusprintf.a

all: $(NAME)

$(LIBFT_OBJS):
	@echo "Compilando libft_bonusprintf..."
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): Makefile $(LIBFT_OBJS)
	@echo "Creando libft_bonusprintf.a..."
	ar rcs $(NAME) $(LIBFT_OBJS)

// %.o: %.c push_swap.h Makefile 

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

