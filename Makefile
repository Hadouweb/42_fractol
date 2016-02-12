CC = gcc -Werror -Wextra -Wall

SRCPATH = ./srcs
INCPATH = ./includes

LIBFT = ./libft
MINILIBX = ./minilibx_macos

HEADER = -I $(LIBFT)/includes -I $(INCPATH) -I $(MINILIBX)

LIB = $(LIBFT)/libft.a $(MINILIBX)/libmlx.a -framework OpenGL -framework AppKit 

SRC = 	$(SRCPATH)/main.c\
		$(SRCPATH)/ft_draw.c\
		$(SRCPATH)/ft_event.c\
		$(SRCPATH)/ft_event_repeat.c\
		$(SRCPATH)/ft_fractal.c\
		$(SRCPATH)/ft_error.c\

OBJ = $(SRC:.c=.o)

NAME = fractol

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	@make -C $(MINILIBX)
	@$(CC) $(HEADER) $(LIB) -o $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(HEADER) -o $@ -c $<
	@echo "\033[32m█\033[0m\c"

clean : 
	@make -C $(LIBFT) clean
	@make -C $(MINILIBX) clean
	rm -rf $(OBJ)

fclean : clean
	@make -C $(LIBFT) fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
