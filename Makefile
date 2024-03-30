NAME = minishell
FLAGS = -Wall -Werror -Wextra -g #-fsanitize=address
INCLUDES = -I ./inc/\
           -I ./libft/\
		   -I ./readline/
SRC = 

DIR_SRC = ./src
DIR_OBJ = $(DIR_SRC)/obj
OBJ = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))
DEP = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.d))

all: dir $(NAME)

-include $(DEP)
dir:
	make -C ./libft/ --no-print-directory
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c Makefile
	$(CC) -MMD $(FLAGS)  -c $< -o $@ $(INCLUDES)
$(NAME): $(OBJ) ./libft/libft.a
	$(CC) $(FLAGS) $(OBJ)  ./libft/libft.a -o $@ $(INCLUDES)
	echo "$(NAME) Created :D"
clean:
	rm -rf $(DIR_OBJ)
	make clean -C ./libft/ --no-print-directory
	echo "DEPENDENCIES Erased :D"
fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft/ --no-print-directory
	echo "EVERYTHING Erased D:"
re: fclean all
.PHONY: fclean all clean re dir
.SILENT: