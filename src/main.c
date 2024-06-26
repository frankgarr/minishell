#include "minishell.h"
#include <string.h>

char **ft_tokenizator(const char *entrada) {
    char **tokens = malloc(1024 * sizeof(char*));
    if (!tokens) {
        fprintf(stderr, "minishell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    char *token;
    int position = 0;
    char *entrada_dup = strdup(entrada); // Duplicar la entrada para usar con strtok

    // Tokenizar la entrada. strtok no maneja directamente las comillas dobles, así que este es un enfoque simplificado
    token = strtok(entrada_dup, " ");
    while (token != NULL) {
        tokens[position] = strdup(token);
        position++;
        token = strtok(NULL, " ");
    }
    tokens[position] = NULL; // Marca el final del array de tokens

    free(entrada_dup); // Liberar la entrada duplicada
    return tokens;
}

int main(int argc, char **argv, char **env)
{
	char	*linea;
	char **args;
	int		i = 0;

	(void)argv;
	if (argc != 1)
		exit(ft_fd_printf(2, MSG_INVALID_ARG) * 0 + 1);
	else
	{
		ft_printf(*env);

		//-----PRUEBAS TOKENIZADOR-----//
		linea = readline("minishell> ");
		if (!linea)
			exit(ft_fd_printf(2, "FALLO LINEA") * 0 + 1);
		args = ft_tokenizator(linea);
		while(args[i] != NULL)
		{
			printf("Token %d: %s\n", i, args[i]);
			i++;
		}
		free(linea);
		free(args);
		//-----PRUEBAS TOKENIZADOR-----//
	}

return (EXIT_SUCCESS);
}
