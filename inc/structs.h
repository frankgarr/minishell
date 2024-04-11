#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum s_token		t_token;
typedef struct s_register	t_reg;
typedef struct s_env	t_env;

enum s_token
{
	SPACE = 0,
	WORD,
	PIPE,
	AND,
	OR,
	REDIRECT_IN,
	REDIRECT_OUT,
	APPEND,
	HERE_DOC,
	S_QUOTE,
	D_QUOTE
};

/* ************************************************************************** */
// 0 SPACE space
// 1 WORD string
// 2 PIPE |
// 3 AND &&
// 4 OR ||
// 5 REDIRECT_IN >
// 6 REDIRECT_OUT <
// 7 APPEND >>
// 8 HERE_DOC <<
// 9 QUOTE ''
// 10 D_QUOTE ""
/* ************************************************************************** */

struct s_register
{
	char				*word;
	t_token				token;
	struct s_register	*next;
};

struct s_env
{
	char	**env;
};

/* ************************************************************************** */

#endif
