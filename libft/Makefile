# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfazi <jfazi@student.42nice.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 14:31:33 by fpalumbo          #+#    #+#              #
#    Updated: 2024/04/24 11:41:12 by jfazi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  PROJECT  ----------------------------------------------------- #
NAME	=		libftprintf.a

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR	=		srcs
HDR_DIR	=		includes
OBJ_DIR	=		objs
LIBFT_DIR =		libft

# ------------  SOURCE FILES  ------------------------------------------------ #

SRC_FLS	=		$(LIBFT_FLS)\

LIBFT_FLS = 	$(LIBFT_DIR)/ft_strlen.c\
				$(LIBFT_DIR)/ft_strdup.c\
				$(LIBFT_DIR)/ft_memset.c\
				$(LIBFT_DIR)/ft_bzero.c\
				$(LIBFT_DIR)/ft_memcpy.c\
				$(LIBFT_DIR)/ft_memmove.c\
				$(LIBFT_DIR)/ft_memchr.c\
				$(LIBFT_DIR)/ft_memcmp.c\
				$(LIBFT_DIR)/ft_strchr.c\
				$(LIBFT_DIR)/ft_strrchr.c\
				$(LIBFT_DIR)/ft_strnstr.c\
				$(LIBFT_DIR)/ft_strncmp.c\
				$(LIBFT_DIR)/ft_calloc.c\
				$(LIBFT_DIR)/ft_atoi.c\
				$(LIBFT_DIR)/ft_substr.c\
				$(LIBFT_DIR)/ft_split.c\
				$(LIBFT_DIR)/ft_isdigit.c\
				$(LIBFT_DIR)/ft_isalpha.c\
				$(LIBFT_DIR)/ft_isalnum.c\
				$(LIBFT_DIR)/ft_isascii.c\
				$(LIBFT_DIR)/ft_isprint.c\
				$(LIBFT_DIR)/ft_toupper.c\
				$(LIBFT_DIR)/ft_tolower.c\
				$(LIBFT_DIR)/ft_striteri.c\
				$(LIBFT_DIR)/ft_strmapi.c\
				$(LIBFT_DIR)/ft_strjoin.c\
				$(LIBFT_DIR)/ft_strtrim.c\
				$(LIBFT_DIR)/ft_putchar_fd.c\
				$(LIBFT_DIR)/ft_putstr_fd.c\
				$(LIBFT_DIR)/ft_putendl_fd.c\
				$(LIBFT_DIR)/ft_putnbr_fd.c\
				$(LIBFT_DIR)/ft_itoa.c\
				$(LIBFT_DIR)/ft_strlcat.c\
				$(LIBFT_DIR)/ft_lstnew_bonus.c\
				$(LIBFT_DIR)/ft_lstdelone_bonus.c\
				$(LIBFT_DIR)/ft_lstdelone_bonus.c\
				$(LIBFT_DIR)/ft_lstadd_front_bonus.c\
				$(LIBFT_DIR)/ft_lstadd_back_bonus.c\
				$(LIBFT_DIR)/ft_lstiter_bonus.c\
				$(LIBFT_DIR)/ft_lstmap_bonus.c\
				$(LIBFT_DIR)/ft_lstclear_bonus.c\
				$(LIBFT_DIR)/ft_lstadd_mid.c\
				$(LIBFT_DIR)/ft_lstdel_mid.c\
				$(LIBFT_DIR)/ft_lstlast_bonus.c\

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		gcc
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra
IFLGS	=		-I $(HDR_DIR)
#DFLGS	=		-MMD -MP -O1

# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re

all: $(NAME)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLGS) $(DFLGS) -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(LIBFT_DIR)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all