
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboualla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 19:52:16 by oboualla          #+#    #+#              #
#    Updated: 2019/11/10 20:20:08 by oboualla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = src/copier_couper2.c src/arrow.c src/history2.c  src/deplacer_mot.c src/get_curpos.c src/history.c src/init_objet.c src/read_line.c src/reprint.c\
	  src/signal.c src/termcap.c src/other_key.c src/auto_complition/auto_completion.c src/auto_complition/complet_line.c\
	  src/auto_complition/couleur.c src/auto_complition/objet.c src/auto_complition/print_ac.c src/auto_complition/readpath2.c\
	  src/auto_complition/readpath.c src/copier_couper.c  get_next_line/get_next_line.c mode_line/if_ctrl_c.c mode_line/modifier_line.c\
		mode_line/pip.c mode_line/quots.c mode_line/replace_home.c mode_line/replace_var.c

OBJ = $(SRC:.c=.o)

EXEC = ft_readline.a

all : EXEC

EXEC : $(OBJ)
	ar rc $(EXEC) $(OBJ)
	ranlib $(EXEC)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(EXEC)

re : fclean all
