/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** loop.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "prototypes.h"
#include "enum.h"

int retrieve_distances(double distances[32])
{
    char *str = NULL;
    size_t n = 0;
    char **tab = NULL;

    write(1, "GET_INFO_LIDAR\n", 15);
    if (getline(&str, &n, stdin) < 0) {
        fputs("Getline error", stderr);
        return (ERROR);
    }
    tab = str_to_arr(str, ":");
    if (!tab || error_handling(tab) == ERROR)
        return (ERROR);
    for (int i = 0; i < 32; i++)
        distances[i] = atof(tab[i + 3]);
    free(str);
    free(tab);
    return (0);
}

int check_lap_end(bool *is_lap_finished)
{
    char *str = NULL;
    size_t n = 0;
    char **tab;

    write(1, "GET_INFO_SIMTIME\n", 17);
    if (getline(&str, &n, stdin) == -1) {
        fputs("Getline error", stderr);
        return (ERROR);
    }
    tab = str_to_arr(str, ":");
    if (strcmp(tab[4], "Track Cleared") == 0)
        *is_lap_finished = true;
    return (0);
}

int movement(bool *is_lap_finished)
{
    double distances[32] = {0};

    if (retrieve_distances(distances) == ERROR)
        return(ERROR);
    if (forward_speed(distances) == ERROR)
        return (ERROR);
    if (check_lap_end(is_lap_finished) == ERROR)
        return (ERROR);
    if (retrieve_distances(distances) == ERROR)
        return (ERROR);
    if (turn(distances) == ERROR)
        return (ERROR);
    if (check_lap_end(is_lap_finished) == ERROR)
        return (ERROR);
    return (0);
}

int loop(void)
{
    bool is_lap_finished = false;
    double speed = 0;

    while (!is_lap_finished) {
        if (movement(&is_lap_finished) == ERROR)
            return (ERROR);
    }
    write(1, "CAR_FORWARD:0\n", 14);
    do {
    speed = retrieve_current_speed();
    } while (speed > 0.01);
    return (0);
}