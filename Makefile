# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 17:35:54 by mde-avel          #+#    #+#              #
#    Updated: 2022/11/29 14:26:00 by mde-avel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = ft_printf.c ft_putnbru.c ft_puthex.c ft_putvod.c

LIBFT = ft_putnbr.c ft_putstr.c ft_putchar.c
			
OBJ = $(SRC:.c=.o)

LOBJ = $(LIBFT:.c=.o)

PRELB = lib/

all:	$(NAME)

$(NAME):	$(OBJ) $(addprefix $(PRELB),$(LOBJ))
			ar rcs $(NAME) $(OBJ) $(addprefix $(PRELB),$(LOBJ))

clean:
			$(RM) $(OBJ) $(LOBJ)

fclean:	clean
			$(RM) $(NAME)

re:	fclean $(NAME)