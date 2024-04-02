# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feaguila <feaguila@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 15:25:54 by feaguila          #+#    #+#              #
#    Updated: 2024/04/02 10:19:40 by feaguila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #

NAME := libft.a

# **************************************************************************** #

GCC := gcc
CFLAGS := -Wall -Wextra -Werror
AR := ar -rcs
RM := rm -fr
MKD := mkdir -p
MKF := Makefile

# **************************************************************************** #

DIR_HEADS := heads/
DIR_OBJS := objs/
DIR_SRCS := srcs/

# **************************************************************************** #


D_CHECK := checks/
D_GLINE := next_line/
D_MEMOR := mem/
D_NUMBR := numbers/
D_PRINT := print/
D_STRGS := string/

D_CHECK_SRC := $(addprefix $(DIR_SRCS),$(D_CHECK))
D_GLINE_SRC := $(addprefix $(DIR_SRCS),$(D_GLINE))
D_MEMOR_SRC := $(addprefix $(DIR_SRCS),$(D_MEMOR))
D_NUMBR_SRC := $(addprefix $(DIR_SRCS),$(D_NUMBR))
D_PRINT_SRC := $(addprefix $(DIR_SRCS),$(D_PRINT))
D_STRGS_SRC := $(addprefix $(DIR_SRCS),$(D_STRGS))

# **************************************************************************** #

FCHEKCS := ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c

FGNLINE := get_next_line.c get_next_line_utils.c

FMEMORY := ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		   ft_memmove.c ft_memset.c

FNUMBER := ft_atoi.c ft_itoa.c ft_utoa.c

FPRINTS := ft_putchar_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c \
		   ft_printf.c ft_checkprint.c ft_putchar.c ft_putstr.c \
		   ft_putnbr.c ft_putnbr_unsigned.c ft_putnbr_hexadecimal.c \
		   ft_putptr.c ft_fd_printf.c

FSTRING := ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
		   ft_strjoin.c ft_strlcat.c ft_strcpy.c ft_strlcpy.c ft_strlen.c \
		   ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		   ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c


# **************************************************************************** #

SRCS := $(FCHEKCS) $(FGNLINE) $(FMEMORY) \
		$(FNUMBER) $(FPRINTS) $(FSTRING)

vpath %.c $(D_CHECK_SRC) $(D_GLINE_SRC) $(D_MEMOR_SRC) \
		  $(D_NUMBR_SRC) $(D_PRINT_SRC) $(D_STRGS_SRC)

# **************************************************************************** #

INCLUDE := -I$(DIR_HEADS)
OBJS := $(addprefix $(DIR_OBJS), $(SRCS:.c=.o))
DEPS := $(OBJS:.o=.d)

# **************************************************************************** #

all: $(DIR_OBJS) $(NAME)

$(DIR_OBJS):
	$(MKD) $(DIR_OBJS)

$(NAME) : $(OBJS)
	$(call show_progress)
	$(AR) $(NAME) $(OBJS)

$(DIR_OBJS)%.o : %.c $(MKF)
	$(GCC) $(CFLAGS) $(INCLUDE) -MMD -c $< -o $@

# **************************************************************************** #

clean:
	$(call check_objects)
	$(RM) $(DIR_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# **************************************************************************** #

.PHONY: all clean fclean re

.SILENT:

-include $(DEPS)

# **************************************************************************** #

BGRAY =	\033[1;90m
BRED = \033[1;91m
BGREEN = \033[1;92m
BYELLOW = \033[1;93m
BBLUE = \033[1;94m
BCIAN = \033[1;96m
BWHITE = \033[1;97m
GRAY =	\033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
CIAN = \033[0;96m
WHITE = \033[0;97m

# **************************************************************************** #

COUNT_SRCS := $(words $(SRCS))
COUNT_OBJS := $(words $(OBJS))
BAR_LEN := 20

# **************************************************************************** #

define show_progress
	clear; \
	echo; \
	((i = 0)); \
	while [[ $$i -le $(COUNT_SRCS) ]] ; do \
		printf "$(BCIAN)➜ Compiling $(basename $(NAME)) $(BBLUE)["; \
		progress=$$((i * $(BAR_LEN) / $(COUNT_SRCS))); \
		((j = 1));\
		while [[ $$j -le $(BAR_LEN) ]]; do \
			if [[ $$j -le $$progress ]]; then \
				printf "$(BGREEN)■"; \
			else \
				printf " "; \
			fi; \
			((j = j + 1)); \
		done; \
		printf "$(BBLUE)] [$(CIAN)$$i/$(COUNT_SRCS)$(BBLUE)] \
		[$(BWHITE)$$((i * 100 / $(COUNT_SRCS)))%%$(BBLUE)]$(WHITE)\r"; \
		((i = i + 1)); \
		sleep 0.05; \
	done
	echo
endef

# **************************************************************************** #

define check_objects
	if [ -d $(DIR_OBJS) ]; then \
		$(call progress_remove); \
	else \
		printf "\n$(YELLOW)➜ There aren't objects to delete [✗]\n"; \
	fi
endef

# **************************************************************************** #

define progress_remove
	echo; \
	((i = 0)); \
	while [[ $$i -le $(COUNT_OBJS) ]] ; do \
		printf "$(BCIAN)➜ Deleting $(basename $(NAME)) $(BBLUE)["; \
		progress=$$((i * $(BAR_LEN) / $(COUNT_OBJS))); \
		((j = 1));\
		while [[ $$j -le $(BAR_LEN) ]]; do \
			if [[ $$j -le $$progress ]]; then \
				printf "$(BRED)■"; \
			else \
				printf " "; \
			fi; \
			((j = j + 1)); \
		done; \
		printf "$(BBLUE)] [$(CIAN)$$i/$(COUNT_OBJS)$(BBLUE)] \
		[$(BRED)$$((i * 100 / $(COUNT_OBJS)))%%$(BBLUE)]$(WHITE)\r"; \
		((i = i + 1)); \
		sleep 0.05; \
	done; \
	echo; \
	printf "\n$(BRED)➜ DELETED OBJECTS  $(basename $(NAME)) [✔]\n"; \
	echo
endef

# **************************************************************************** #
