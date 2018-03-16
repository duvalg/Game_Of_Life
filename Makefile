# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/27 11:25:13 by gduval            #+#    #+#              #
#    Updated: 2017/07/27 11:25:16 by gduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			Game_Of_Life

LIBFTNAME = 	libft.a
LIBFTDIR = 		libft/
LIBFT = 		$(addprefix $(LIBFTDIR), $(LIBFTNAME))

MLXNAME = 		libmlx.a
MLXDIR = 		minilibx_macos/
MLX = 			$(addprefix $(MLXDIR), $(MLXNAME))

SRCDIR = 		srcs/
SRCNAME = 		main.c					\
				exitProgram.c			\

SRC = 			$(addprefix $(SRCDIR), $(SRCNAME))

OBJDIR = 		obj/
OBJNAME = 		$(SRCNAME:.c=.o)
OBJ = 			$(addprefix $(OBJDIR), $(OBJNAME))

FLAGS = 		-Werror -Wextra -Wall -O2
LFLAGS = 		-lpthread -D_REENTRANT -framework OpenGL -framework Appkit
CC = 			gcc

all: 			$(NAME)

$(OBJDIR)%.o:	$(SRCDIR)%.c
	$(CC) $(FLAGS) -o $@ -c $<

createdir:
	make -C $(LIBFTDIR)
	make -C $(MLXDIR)
	mkdir -p $(OBJDIR) 2> /dev/null || true

$(NAME): 		createdir $(OBJ)
	$(CC) $(LFLAGS) $(LIBFT) $(MLX) $(SRC) -o $@

clean:
	make clean -C $(LIBFTDIR)
	make clean -C $(MLXDIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFTDIR)
	make fclean -C $(MLXDIR)
	rm -f $(NAME)
	rm -rf $(OBJDIR)

re: fclean all

.PHONY: all opti createdir clean fclean re
