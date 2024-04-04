/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feaguila <feaguila@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:29:46 by fer               #+#    #+#             */
/*   Updated: 2024/02/07 12:03:47 by feaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* ************************************************************************** */

# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/uio.h>

/* ************************************************************************** */

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

/* ************************************************************************** */

# define C_RED "\033[1;31m"
# define C_NORMAL "\033[0m"

# define ERROR_ARG "➜ pipex: Invalid number of arguments\n"
# define ERROR_STRUCT "➜ pipex: Failed to alloc memory\n"

# define ERROR_PIPE "➜ pipex: Failed to open pipe\n"
# define ERROR_FORK "➜ pipex: Failed to create fork\n"

# define ERROR_PIPE_FD "➜ pipex: No found file descriptor\n"
# define ERROR_ARGV_2 "➜ pipex: No found argv[2]\n"
# define ERROR_OPEN_FILE "➜ pipex: No such file or directory\n"
# define ERROR_PERMISSION "➜ pipex: Permision denied\n"
# define ERROR_CMD "Command not found\n"

# define ERROR_DUP_IN "➜ pipex: Error to create dup in_file\n"
# define ERROR_DUP_OUT "➜ pipex: Error to create dup out_file\n"
# define ERROR_CREATE_FILE "➜ pipex: Error to create file\n"

/* ************************************************************************** */

# define ERROR -1

/* ************************************************************************** */

# define PATH "PATH="
# define DEFAULT_PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin"

/* ************************************************************************** */

typedef struct s_args
{
	int		argc;
	char	**argv;
	char	**env;
}	t_args;

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		pipe_fd[2];

	int		in_dup;
	int		out_dup;

	char	*in_name;
	char	*out_name;
	char	*in_cmmd;
	char	*out_cmmd;

	char	**in_cmd;
	char	**out_cmd;

	pid_t	in_pid;
	pid_t	out_pid;

	char	**paths;
	char	*path;
	int		exec;

	int		e_status;

	t_args	args;
}	t_pipex;

/* ************************************************************************** */

int		ft_init_struct(int argc, char **argv, char **env, t_pipex *pipex);
int		ft_pipe(t_pipex *pipex);
int		ft_fork(t_pipex *pipex);
int		ft_exec_cmd(t_pipex *pipex, char **cmd);

/* ************************************************************************** */

int		ft_check_args(int argc);
char	*ft_get_path(char *cmd, t_pipex *pipex);
int		ft_print_error(char *str);

/* ************************************************************************** */

int		ft_free_path(t_pipex *pipex);
int		ft_free_paths(t_pipex *pipex);
int		ft_free_args(t_pipex *pipex);
int		ft_free_env(t_pipex *pipex);
int		ft_free_pipex(t_pipex *pipex);
int		ft_close_fd(t_pipex *pipex);

/* ************************************************************************** */

int		ft_create_in_child(t_pipex *pipex);

/* ************************************************************************** */

int		ft_create_out_child(t_pipex *pipex);

/* ************************************************************************** */

#endif
