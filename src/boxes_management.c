/*
** EPITECH PROJECT, 2018
** boxes_management
** File description:
** les caisses
*/

#include <stdlib.h>
#include <stdio.h>
#include "../inc/sokoban.h"

int number_boxes(char *buffer)
{
    int counter = 0;
    int i = 0;

    while (buffer[counter] != '\0') {
        if (buffer[counter] == 'X')
            i++;
        counter++;
    }
    return (i);
}

int *position_boxes(char *buffer)
{
    int i = 0;
    int nbr_X = number_boxes(buffer);
    int *boxes_position = malloc(sizeof(int) * (nbr_X + 1));
    int n = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'X') {
            boxes_position[n] = i;
            n++;
        }
        i++;
    }
    return (boxes_position);
}
