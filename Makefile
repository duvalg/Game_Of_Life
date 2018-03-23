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

LIBFTNAME = 		libft.a
LIBFTDIR = 		libft/
LIBFT = 		$(addprefix $(LIBFTDIR), $(LIBFTNAME))

MLXNAME = 		libmlx.a
MLXDIR = 		minilibx_macos/
MLX = 			$(addprefix $(MLXDIR), $(MLXNAME))

SRCNAME = 		main.c					\
			initStructs.c				\
			parser.c				\
			createMap.c				\
			exitProgram.c
SRCDIR = 		srcs/
SRC = 			$(addprefix $(SRCDIR), $(SRCNAME))

OBJNAME = 		$(SRCNAME:.c=.o)
OBJDIR = 		obj/
OBJ = 			$(addprefix $(OBJDIR), $(OBJNAME))

FLAGS = 		-Werror -Wextra -Wall -O3
LFLAGS = 		-lpthread -D_REENTRANT -framework OpenGL -framework Appkit
CC = 			gcc

all: 			$(NAME)

$(OBJDIR)%.o:		$(SRCDIR)%.c
	$(CC) $(FLAGS) -o $@ -c $<

createdir:
	make -C $(LIBFTDIR)
	make -C $(MLXDIR)
	mkdir -p $(OBJDIR) 2> /dev/null || true

$(NAME): 		createdir $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $@

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

.PHONY: all createdir clean fclean re
