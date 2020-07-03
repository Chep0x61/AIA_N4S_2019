/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** retrieve_current_speed.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"
#include "enum.h"

double retrieve_max_speed(void)
{
    char *str = NULL;
    size_t n = 0;
    char **tab;
    double max_speed;

    write(1, "GET_CURRENT_SPEED\n", 18);
    if (getline(&str, &n, stdin) == -1)
        return (ERROR);
    tab = str_to_arr(str, ":");
    if (!tab) {
        free(str);
        return (-1);
    }
    max_speed = atof(tab[3]);
    free(str);
    free(tab);
    return (max_speed);
}

double retrieve_current_speed(void)
{
    char *str = NULL;
    size_t n = 0;
    char **tab;
    double speed;
    double max_speed = retrieve_max_speed();

    if (max_speed <= 0)
        return (-1);
    write(1, "GET_CAR_SPEED_MAX\n", 18);
    if (getline(&str, &n, stdin) < 0)
        return (-1);
    tab = str_to_arr(str, ":");
    if (!tab) {
        free(str);
        return (-1);
    }
    speed = atof(tab[3]) / max_speed;
    free(str);
    free(tab);
    return (speed);
}