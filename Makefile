# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfontain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 04:52:55 by tfontain          #+#    #+#              #
#    Updated: 2016/12/05 01:58:05 by tfontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
FLAG = -Wall -Wextra -Werror
OPTION = -c
PATH_FILLIT = ./srcs/
HEADER = $(PATH_FILLIT)header.h
PATH_LIBFT = ./libft_files/
SRC_FILLIT = ft_input.c ft_print_result.c  main.c ft_file_functions.c \
			 ft_compare.c ft_define_tetriminos.c ft_algo.c ft_decal.c
SRC_LIBFT = ft_memccpy.c ft_putnbr.c ft_strequ.c ft_strnequ.c ft_memchr.c \
	ft_putnbr_fd.c ft_striter.c ft_strnew.c ft_atoi.c ft_memcmp.c \
	ft_putstr.c ft_striteri.c ft_strnstr.c ft_bzero.c ft_memcpy.c \
	ft_putstr_fd.c ft_strjoin.c ft_strrchr.c ft_isalnum.c ft_memdel.c \
	ft_strcat.c ft_strlcat.c ft_strsplit.c ft_isalpha.c ft_memmove.c \
	ft_strchr.c ft_strlen.c ft_strstr.c ft_isascii.c ft_memset.c \
	ft_strclr.c ft_strmap.c ft_strsub.c ft_isdigit.c ft_putchar.c \
	ft_strcmp.c ft_strmapi.c ft_strtrim.c ft_isprint.c ft_putchar_fd.c \
	ft_strcpy.c ft_strncat.c ft_tolower.c ft_itoa.c ft_putendl.c \
	ft_strdel.c ft_strncmp.c ft_toupper.c ft_memalloc.c ft_putendl_fd.c \
	ft_strdup.c ft_strncpy.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
	ft_lstiter.c ft_lstmap.c ft_lstnew.c
SRC = $(addprefix $(PATH_LIBFT),$(SRC_LIBFT)) \
	  $(addprefix $(PATH_FILLIT),$(SRC_FILLIT))
OBJ = $(addsuffix .o,$(basename $(SRC_FILLIT), $(basename $(SRC_LIBFT))))

all : $(NAME)

$(NAME) :
		$(CC) $(FLAG) $(OPTION) $(SRC)
		$(CC) $(OBJ) -o $(NAME)

clean :
		rm -f $(OBJ)
fclean : clean
		rm -f $(NAME)

re : fclean all

no_object :
	$(CC) $(FLAG) $(SRC) -o $(NAME)
