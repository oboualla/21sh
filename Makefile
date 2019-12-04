# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/17 21:22:15 by kbahrar           #+#    #+#              #
#    Updated: 2019/12/04 06:37:26 by oboualla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh
SRC = main.c env/access_file.c env/do_cd.c env/ft_echo.c env/ft_free.c  parse/ret_heredoc.c env/ft_vars.c env/make_env.c env/setenv.c env/unsetenv.c exec/exec.c exec/ft_pipe.c exec/redirec.c mode_line/make_param.c parse/ft_retval.c parse/make_red.c parse/parse_line.c mode_line/prompt.c
OBJ = $(SRC:.c=.o)
LIBF = libft/libft.a
LIBR = ft_readline/ft_readline.a
LIBS = 21sh.a

all:$(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@make -C ft_readline/
	@ar rc $(LIBS) $(OBJ)
	@ranlib $(LIBS)
	gcc -Wall -Wextra -Werror $(LIBS) $(LIBR) $(LIBF) -o $(NAME) -ltermcap

clean:
	rm -rf $(OBJ)
	rm -rf $(LIBS)
	make clean -C libft/
	make clean -C ft_readline/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/
	make fclean -C ft_readline/

re: fclean all
	@make re -C libft/

%.o : %.c
	@gcc -Wall -Wextra -Werror -c $< -o $@
