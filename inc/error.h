#ifndef ERROR_H
# define ERROR_H

# define MSG_INVALID_ARG "➜ Invalid of argument\n"

/* ************************************************************************** */

# define CMD_NO_ACCESS 126
# define CMD_NOT_FOUND 127

/* ************************************************************************** */

typedef enum s_error
{
	NONE = 0,
	QUOTE,
	NOTDIR,
	NOTPERM,
	NOTCMD,
	DUPERR,
	FORKERR,
	PIPERR,
	MEM
}	t_error;

#endif
