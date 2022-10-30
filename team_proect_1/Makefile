# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 13:42:32 by junoh             #+#    #+#              #
#    Updated: 2022/10/21 12:44:37 by junoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	beyond.c \
		check_num.c \
		print.c \
		util.c\
		calculate_num.c\
		plus.c\
		minus.c\
			
OBJ = $(SRC:.c=.o)
CC = gcc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g3
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address

NAME = beyond

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
