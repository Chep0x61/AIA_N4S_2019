/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** turn.c
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "prototypes.h"
#include "dist_speed_arrays.h"
#include "enum.h"

int turn(double *dist)
{
    int i = 0;
    double coeff = LEFT_LIDAR(dist) - RIGHT_LIDAR(dist);
    double distance = MID_LIDAR(dist);
    char *str = NULL;
    size_t n = 0;
    char **tab;

    for (; i < 6 && distance < wall_distances[i]; i += 1);
    if (coeff < 0)
        write(1, wheels_arr_n[i], strlen(wheels_arr_n[i]));
    else
        write(1, wheels_arr_p[i], strlen(wheels_arr_p[i]));
    if (getline(&str, &n, stdin) == -1)
        return (ERROR);
    tab = str_to_arr(str, ":");
    if (!tab || error_handling(tab) == ERROR)
        return (ERROR);
    return (0);
}