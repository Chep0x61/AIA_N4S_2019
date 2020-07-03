/*
** EPITECH PROJECT, 2020
** n4s
** File description:
** main
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "error_code.h"
#include "prototypes.h"
#include "enum.h"

int error_handling(char **tab)
{
    int nb = atoi(tab[0]);

    if (nb > 25 || nb < 0) {
        fputs(str_error[4], stderr);
        return (ERROR);
    } else if (nb != 1) {
        fputs(str_error[nb], stderr);
        return (ERROR);
    }
    if (strcmp(tab[1], "KO") == 0) {
        fputs(str_error[3], stderr);
        return (ERROR);
    }
    return (0);

}

int main(void)
{
    int check = 0;
    char *str = NULL;
    size_t n = 0;
    char **tab;

    setvbuf(stdout, NULL, _IONBF, 0);
    write(1, "START_SIMULATION\n", 17);
    if (getline(&str, &n, stdin) == -1)
        return (ERROR);
    tab = str_to_arr(str, ":");
    if (error_handling(tab) == ERROR)
        return (ERROR);
    free(str);
    free(tab);
    check = loop();
    write(1, "STOP_SIMULATION\n", 16);
    return (check);
}
