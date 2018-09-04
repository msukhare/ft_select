# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msukhare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 15:46:51 by msukhare          #+#    #+#              #
#    Updated: 2018/03/08 18:04:43 by msukhare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs/

SRC_NAME = main.c\
	ft_select.c\
	ft_return.c\
	ft_refresh.c\
	ft_readcmd.c\
	ft_putlist.c\
	ft_putcurse.c\
	ft_mv_left_right.c\
	ft_mv_curse.c\
	ft_manage_sig.c\
	ft_getallsignal.c\
	ft_freetab_lst.c\
	ft_escape.c\
	ft_dellink.c\
	ft_creatlist.c\
	ft_chang_curs.c\

OBJ_PATH = obj/

CPPFLAGS = -I includes/ -I libft/include/

NAME = ft_select

CC = gcc

MK = make -C

SRCLFT = libft/

LFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(MK) $(SRCLFT)
	$(CC) $(CFLAGS) -o $(NAME) $(CPPFLAGS) $(OBJ) $(LFT) -ltermcap

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C $(SRCLFT)
	@rm -vf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C $(SRCLFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
