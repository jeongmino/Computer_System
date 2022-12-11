
SRC	=	show_bits.c\
		plus.c\
		operation.c\
		and_or_xor_operation.c\
		shift.c\
		not_operation.c\

			
OBJ = $(SRC:.c=.o)
CC = gcc 
RM = rm -f
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address

NAME = beyond

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re