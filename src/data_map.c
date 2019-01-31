/*
** EPITECH PROJECT, 2018
** position_map
** File description:
** map data and position
*/

#include <stdlib.h>

int position_player(char *buffer)
{
    int i = 0;

    while (buffer[i] != 'P')
        i++;
    return (i);
}

int number_columns(char *buffer)
{
    int i = 0;
    int columns = 0;

    while (buffer[i] != '\n') {
        columns++;
        i++;
    }
    columns += 1;
    return (columns);
}
