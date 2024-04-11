#ifndef MINISHELL_H
# define MINISHELL_H

/* ************************************************************************** */

# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <sys/ioctl.h>

/* ************************************************************************** */

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"

/* ************************************************************************** */

# include "colors.h"
# include "error.h"
# include "structs.h"

#endif
