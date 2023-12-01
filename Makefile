NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
AR			= ar -rc
LIBFT_DIR	= libft
LIBFT_LIB	= libft.a
LIBFT		= $(LIBFT_DIR)/$(LIBFT_LIB)

SRC = ft_printf.c functions.c functions2.c functions3.C

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -c $(SRC)
	@$(AR) $(NAME) $(OBJ) $(LIBFT_DIR)/*.o
	@echo "Created" $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo "Cleaned object files"

fclean: clean
	@$(RM) $(NAME)
	@echo "Cleaned object and archive files"

re: fclean all
	@echo "Updated"