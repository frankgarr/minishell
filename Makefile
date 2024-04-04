NAME = minishell
FLAGS = -Wall -Werror -Wextra -g #-fsanitize=address
INCLUDES = -I ./inc/\
           -I ./libft/\
		   -I ./readline/

SRC = main.c

DIR_SRC = ./src
DIR_OBJ = $(DIR_SRC)/objs
OBJ = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))
DEP = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.d))

all: readline dir $(NAME)

readline:
		curl https://ftp.gnu.org/gnu/readline/readline-8.2.tar.gz -o readline
		tar -xf readline
		rm readline
		mv readline-8.2 readline
		cd readline && ./configure

dir:
	make -C ./readline/ --no-print-directory
	make -C ./libft/ --no-print-directory
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c Makefile
	$(CC) -MMD $(FLAGS)  -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJ) ./libft/libft.a
	$(CC) $(FLAGS) $(OBJ)  ./libft/libft.a -o $@ $(INCLUDES)
	echo "$(NAME) Created :D"

-include $(DEP)

clean:
	rm -rf $(DIR_OBJ)
	make clean -C ./libft/ --no-print-directory
	echo "DEPENDENCIES Erased :D"
fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft/ --no-print-directory
	echo "EVERYTHING Erased D:"
re: fclean all
.PHONY: all re dir fclean clean
.SILENT:
