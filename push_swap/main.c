/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:26:35 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/23 14:04:48 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        write(1, "Error: falta argumento\n", 23);
        return 1;
    }

    printf("Argumentos recibidos:\n");
    for (int i = 1; i < argc; i++)
        printf("argv[%d]: '%s'\n", i, argv[i]);

    if (!validate_args(argc - 1, argv + 1))
    {
        write(1, "Validacion fallida\n", 19);
        return 1;
    }

    printf("Todos los argumentos son válidos y sin duplicados\n");

    // Mostrar los tokens separados
    char **tokens = split_args(argc - 1, argv + 1);
    if (!tokens)
    {
        write(1, "Error en split_args\n", 19);
        return 1;
    }

    printf("Tokens separados:\n");
    int i = 0;
    while (tokens[i])
    {
        printf("Token[%d]: '%s'\n", i, tokens[i]);
        i++;
    }

    free_split(tokens);
    return 0;
}
