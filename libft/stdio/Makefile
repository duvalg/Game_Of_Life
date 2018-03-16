# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/04 11:10:28 by gduval            #+#    #+#              #
#    Updated: 2017/08/04 11:10:31 by gduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER_PATH = ./../
HEADER_NAME = libft.a
HEADER = $(addprefix $(HEADER_PATH), $(HEADER_NAME))

SRC_PATH = ./srcs/
SRC_NAME = ft_printf.c 				\
		   start_read.c				\
		   init_struct.c			\
		   count_params.c			\
		   check_types.c			\
		   fill_params.c			\
		   get_width.c				\
		   get_precision.c			\
		   add_precision.c			\
		   add_precision_nb.c		\
		   add_plus.c				\
		   add_hash.c				\
		   add_space.c				\
		   width_gestion.c			\
		   width_gestion_unicode.c	\
		   width_gestion_special.c	\
		   flags_gestion.c			\
		   flags_gestionhexa.c		\
		   flags_octal.c			\
		   print.c					\
		   print_hexa.c				\
		   print_octal.c			\
		   print_unsigned.c			\
		   print_string.c			\
		   print_unicode.c			\
		   ft_strwlenplus.c			\
		   ft_putstri.c				\
		   normalize_flags.c		\
		   ft_putwchar.c			\
		   ft_putwstr.c				\
		   ft_itoa_basemax.c		\
		   ft_atoi_max.c			\
		   upper.c					\
		   ft_exit.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(SRC_NAME:.c=.o)

LIBFT_PATH = ./../
LIBFT_SRC_NAME = ft_memset.c 		\
	  ft_bzero.c					\
	  ft_memcpy.c					\
	  ft_memccpy.c					\
	  ft_memmove.c					\
	  ft_memchr.c					\
	  ft_memcmp.c					\
	  ft_strlen.c					\
	  ft_strwlen.c					\
	  ft_strdup.c					\
	  ft_strwdup.c					\
	  ft_strcpy.c					\
	  ft_strncpy.c					\
	  ft_strcat.c					\
	  ft_strncat.c					\
	  ft_strlcat.c					\
	  ft_strchr.c					\
	  ft_strrchr.c					\
	  ft_strstr.c					\
	  ft_strnstr.c					\
	  ft_strcmp.c					\
	  ft_strncmp.c					\
	  ft_atoi.c						\
	  ft_isalpha.c					\
	  ft_isdigit.c					\
	  ft_isalnum.c					\
	  ft_isascii.c					\
	  ft_isprint.c					\
	  ft_toupper.c					\
	  ft_tolower.c					\
	  ft_memalloc.c					\
	  ft_memdel.c					\
	  ft_strnew.c					\
	  ft_strdel.c					\
	  ft_strclr.c					\
	  ft_striter.c					\
	  ft_striteri.c					\
	  ft_strmap.c					\
	  ft_strmapi.c					\
	  ft_putchar.c					\
	  ft_putstr.c					\
	  ft_putnbr.c					\
	  ft_strequ.c					\
	  ft_strnequ.c					\
	  ft_strsub.c					\
	  ft_strwsub.c					\
	  ft_strjoin.c					\
	  ft_strwjoin.c					\
	  ft_putchar_fd.c				\
	  ft_putstr_fd.c				\
	  ft_putnbr_fd.c				\
	  ft_putendl.c					\
	  ft_putendl_fd.c				\
	  ft_strtrim.c					\
	  ft_strsplit.c					\
	  ft_itoa.c						\
	  ft_itoa_base.c				\
	  ft_intlen.c					\
	  ft_intlen_base.c				\
	  ft_lstnew.c					\
	  ft_lstdelone.c				\
	  ft_lstdel.c					\
	  ft_lstadd.c					\
	  ft_lstiter.c					\
	  ft_lstmap.c					\
	  ft_deletestr.c				\
	  ft_reverse.c					\
	  ft_power.c					\
	  ft_bitoi.c

LIBFT_SRC = $(addprefix $(LIBFT_PATH), $(LIBFT_SRC_NAME))
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

FLAG = -c Werror Wall Wextra

all : $(NAME)

$(NAME) :
	gcc $(FLAGS) $(SRC) ../libft.a

clean :
	@rm -f $(OBJ)

fclean :
	@rm -f $(OBJ) $(NAME)

re : fclean $(NAME)

.PHONY : all build_project clean fclean re
