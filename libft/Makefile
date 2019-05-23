# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 17:31:03 by fbrekke           #+#    #+#              #
#    Updated: 2019/05/01 03:30:36 by ehaggon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_strlen.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strdup.c \
				ft_strndup.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_isascii.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strnew.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_strsplit.c \
				ft_itoa.c \
				ft_whitesp.c \
				ft_num_words.c \
				ft_word_len.c \
				ft_bit_depth.c \
				ft_freefree.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				ft_lstadd.c \
				ft_lstnew.c \
				ft_lstiter.c \
				ft_lstmap.c \
				get_next_line.c \
				printb_64.c \
				printb_16.c \
				printb_ch.c \
				ft_putstr_col.c \
				ft_abs.c \
				ft_report.c \
				ft_strtok.c \
				ft_chrstr.c \
				ft_pars.c \
				ft_fuck.c \

NAME = libft.a
OBJ = $(SRCS:%.c=%.o)
FLAG = -Wall -Werror -Wextra -I. -c

all: $(NAME)

$(NAME): $(OBJ)
		ar -rcs $(NAME) $(OBJ)

$(OBJ): $(SRCS)
		gcc $(FLAG) $(SRCS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
