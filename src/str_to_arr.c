/*
** EPITECH PROJECT, 2020
** tab lib
** File description:
** returns array based on a given str of delim
*/

#include <stddef.h>
#include <malloc.h>
#include <string.h>

char **str_to_arr(char *str, char *delim)
{
    char **tab = calloc(2, sizeof(char *));
    char *token;
    int i = 0;

    if (!str || !delim || !tab)
        return (NULL);
    token = strtok(str, delim);
    if (!token)
        return (NULL);
    while (token) {
        tab[i] = token;
        token = strtok(NULL, delim);
        i += 1;
        tab = reallocarray(tab, i + 2, sizeof(char *));
        if (!tab)
            return (NULL);
        tab[i + 1] = NULL;
    }
    return (tab);
}