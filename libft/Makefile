# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/31 20:59:16 by oboualla          #+#    #+#              #
#    Updated: 2019/11/27 14:40:21 by oboualla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a 

CC = gcc -Wall -Wextra -Werror

rm = rm -rf

SRC =	ft_strchr_index.c ft_atoi.c ft_bzero.c ft_change_chr_to_nwchr.c\
		ft_count_char.c ft_count_to_find.c ft_count_word.c\
		free_double.c ft_is_separ.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c\
		ft_itoa.c ft_lstadd.c ft_lstdel.c\
		ft_lstdelone.c ft_lstiter.c ft_lstmap.c\
		ft_lstnew.c ft_memalloc.c ft_memccpy.c\
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c\
		ft_memmove.c ft_memset.c ft_new_lst.c \
		ft_putchar.c ft_putchar_fd.c ft_putendl.c \
		ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
		ft_putstr.c ft_putstr_fd.c ft_rev.c \
		ft_reverse.c ft_skip_lensep.c ft_skip_sep.c \
		ft_sqrt.c ft_strcat.c ft_strccpy.c \
		ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
		ft_strdel.c ft_strdup.c ft_strequ.c \
		ft_striter.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlen.c ft_strmap.c \
		ft_strmapi.c ft_strncat.c ft_getchr.c ft_strncmp.c ft_strccmp.c\
		ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
		ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strsubdel.c \
		ft_strtrim.c ft_tolower.c ft_toupper.c ft_wordlen.c ft_remplacer_str.c ft_strcdup.c ft_strndup.c ft_pathjoin.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c
	$(CC) -c $< -o $@

clean :
	$(rm) *.o

fclean : clean
	$(rm) $(NAME)

re : fclean all

