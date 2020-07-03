/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** forward_speed.c
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "prototypes.h"
#include "dist_speed_arrays.h"
#include "enum.h"

int forward_speed(const double *dist)
{
    double wall_dist = MID_LIDAR(dist);
    int i = 0;
    char *str = NULL;
    size_t n = 0;
    char **tab;

    for (; i < 6 && wall_dist < wall_distances[i]; i++);
    write(1, speed_arr[i], strlen(speed_arr[i]));
    if (getline(&str, &n, stdin) == -1)
        return (ERROR);
    tab = str_to_arr(str, ":");
    if (!tab || error_handling(tab) == ERROR)
        return (ERROR);
    return (0);
}