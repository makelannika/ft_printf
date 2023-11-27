# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 17:52:26 by amakela           #+#    #+#              #
#    Updated: 2023/11/27 20:58:55 by amakela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

LIBFTDIR = libft

CFILES = ft_printf.c	ft_printchar.c	ft_printstr.c	\
		 ft_printnbr.c	ft_printhex.c

CFLAGS = -Wall -Wextra -Werror

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES) $(LIBFT)
	ar rcs $(NAME) $(OFILES)

$(LIBFT):
	make -C $(LIBFTDIR)

clean:
	rm -f $(OFILES)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
