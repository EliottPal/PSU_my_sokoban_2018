/*
** EPITECH PROJECT, 2018
** storage_management
** File description:
** manage storage
*/

#include <stdlib.h>
#include <stdio.h>

int number_storage(char*buffer)
{
    int i = 0;
    int j = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'O') {
            j++;
        }
        i++;
    }
    return (j);
}

int *position_storage(char *buffer)
{
    int i = 0;
    int nbr_O = number_storage(buffer);
    int *storage_position = malloc(sizeof(int) * (nbr_O + 1));
    int n = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'O') {
            storage_position[n] = i;
            n++;
        }
        i++;
    }
    return (storage_position);
}

void reprint_storage(char* buffer)
{
    int total_storage = number_storage(buffer);
    int *storage_position = position_storage(buffer);
    int counter = 0;
    int i;

    while (counter < total_storage) {
        i = storage_position[counter];
        if (buffer[i] == ' ')
            buffer[i] = 'O';
        counter++;
    }
}
