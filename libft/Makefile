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

NAME = 			libft.a

HEADERDIR = 	includes/
HEADERNAME = 	libft.h
HEADER = 		$(addprefix $(HEADERDIR), $(HEADERNAME))

SRCDIR = 		srcs/
SRCNAME = 		ft_memset.c			\
				ft_bzero.c			\
				ft_memcpy.c			\
				ft_memccpy.c		\
				ft_memmove.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_strlen.c			\
				ft_strdup.c			\
				ft_strcpy.c			\
				ft_strncpy.c		\
				ft_strcat.c			\
				ft_strncat.c		\
				ft_strlcat.c		\
				ft_strchr.c			\
				ft_strchri.c		\
				ft_strrchr.c		\
				ft_strstr.c 		\
				ft_strnstr.c		\
				ft_strcmp.c			\
				ft_strncmp.c		\
				ft_atoi.c			\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_memalloc.c		\
				ft_memdel.c			\
				ft_strnew.c			\
				ft_strdel.c			\
				ft_strclr.c			\
				ft_striter.c		\
				ft_striteri.c		\
				ft_strmap.c			\
				ft_strmapi.c		\
				ft_putchar.c		\
				ft_putstr.c			\
				ft_putnbr.c			\
				ft_strequ.c			\
				ft_strnequ.c		\
				ft_strsub.c			\
				ft_strjoin.c		\
				ft_strjoin_free.c 	\
				ft_putchar_fd.c 	\
				ft_putstr_fd.c		\
				ft_putnbr_fd.c		\
				ft_putendl.c		\
				ft_putendl_fd.c		\
				ft_strtrim.c		\
				ft_strsplit.c		\
				ft_itoa.c			\
				ft_itoa_base.c		\
				ft_intlen.c			\
				ft_intlen_base.c	\
				ft_lstnew.c			\
				ft_lstdelone.c		\
				ft_lstdel.c			\
				ft_lstadd.c			\
				ft_lstiter.c		\
				ft_lstmap.c			\
				get_next_line.c		\
				ft_deletestr.c		\
				ft_power.c

SRC = 			$(addprefix $(SRCDIR), $(SRCNAME))

OBJDIR = 		obj/
OBJNAME = 		$(SRCNAME:.c=.o)
OBJ = 			$(addprefix $(OBJDIR), $(OBJNAME))

FLAGS = 		-c -Werror -Wall -Wextra
CC = 			gcc

$(OBJDIR)%.o:	$(SRCDIR)%.c
	$(CC) $(FLAGS) -o $@ -c $<

all: 			$(NAME)

createdir:
	mkdir -p $(OBJDIR) 2> /dev/null || true

$(NAME):		createdir $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re
