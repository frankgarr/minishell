#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

// Función para tokenizar respetando las comillas dobles
char **tokenizar(const char *entrada) {
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

int main(void) {
    char *linea;
    char **args;
    int i;

    // Leer una línea de entrada
    linea = readline("minishell> ");
    if (!linea) {
        printf("\n");
        exit(EXIT_SUCCESS);
    }

    // Tokenizar la entrada
    args = tokenizar(linea);

    // Imprimir tokens
    for (i = 0; args[i] != NULL; i++) {
        printf("Token %d: %s\n", i, args[i]);
    }

    // Liberar memoria
    free(linea);
    free(args);
    return 0;
}
