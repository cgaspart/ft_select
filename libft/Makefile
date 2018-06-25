# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 10:42:03 by cgaspart          #+#    #+#              #
#    Updated: 2018/04/30 08:29:04 by cgaspart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJ_PATH = obj
CFLAGS = -Wall -Wextra -Werror
OPTION = -c
SRC_NAME = ft_putchar.c\
	  ft_putstr.c\
	  ft_strlen.c\
	  ft_putnbr.c\
	  ft_isalpha.c\
	  ft_strcmp.c\
	  ft_strncmp.c\
	  ft_strcpy.c\
	  ft_strncpy.c\
	  ft_strcat.c\
	  ft_strncat.c\
	  ft_strdup.c\
	  ft_atoi.c\
	  ft_strstr.c\
	  ft_isdigit.c\
	  ft_isalnum.c\
	  ft_isascii.c\
	  ft_isprint.c\
	  ft_toupper.c\
	  ft_tolower.c\
	  ft_strchr.c\
	  ft_strrchr.c\
	  ft_strlcat.c\
	  ft_strnstr.c\
	  ft_memset.c\
	  ft_bzero.c\
	  ft_memcpy.c\
	  ft_memccpy.c\
	  ft_memmove.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memalloc.c\
	  ft_memdel.c\
	  ft_strnew.c\
	  ft_strdel.c\
	  ft_strclr.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strequ.c\
	  ft_strnequ.c\
	  ft_strsub.c\
	  ft_strjoin.c\
	  ft_strtrim.c\
	  ft_strsplit.c\
	  ft_itoa.c\
	  ft_putendl.c\
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  ft_putendl_fd.c\
	  ft_putnbr_fd.c\
	  ft_lstnew.c\
	  ft_lstdelone.c\
	  ft_lstdel.c\
	  ft_lstadd.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_puttab.c\
	  ft_tabascii.c\
	  ft_print_space.c\
	  ft_issame.c\
	  ft_tabrev_ascii.c\
	  ft_skip_flag.c\
	  ft_tablen.c\
	  ft_add_path.c\
	  ft_rm_path.c\
	  ft_swap.c\
	  ft_intlen.c\
	  ft_free_tab.c\
	  ft_str_fjoin.c\
	  ft_buffer.c\
	  ft_strrealloc.c\
	  get_next_line.c\
	  get_nbr_word.c\
	  ft_type.c\
	  ft_split_whitespaces.c\
	  ft_fatal.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ_PATH)/%.o: %.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(CFLAGS) -Iincludes -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -f $(NAME)

supp: fclean
	/bin/rm -f a.out

re: fclean all

.PHONY: all, clean, fclean, re
