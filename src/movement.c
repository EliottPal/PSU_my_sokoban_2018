/*
** EPITECH PROJECT, 2018
** movement
** File description:
** movement management
*/

#include "../inc/sokoban.h"
#include <ncurses.h>


void move_right(char *buffer)
{
    int position = position_player(buffer);

    if (buffer[position + 1] == 'X' && buffer[position + 2] == 'X') {
    }
    else if (buffer[position + 1] == 'X' && buffer[position + 2] != '#') {
        buffer[position] = ' ';
        buffer[position + 1] = 'P';
        buffer[position + 2] = 'X';
    }
    else  if (buffer[position + 1] == 'X' && buffer[position + 2] == '#') {
    }

    else if (buffer[position + 1] != '#' && buffer[position + 1] != 'O') {
        buffer[position] = ' ';
        buffer[position + 1] = 'P';
    }
}

void move_left(char *buffer)
{
    int position = position_player(buffer);

    if (buffer[position - 1] == 'X' && buffer[position - 2] == 'X') {
    }
    else if (buffer[position - 1] == 'X' && buffer[position - 2] != '#') {
        buffer[position] = ' ';
        buffer[position - 1] = 'P';
        buffer[position - 2] = 'X';
    }
    else if (buffer[position - 1] == 'X' && buffer[position - 2] == '#') {
    }
    else if (buffer[position - 1] != '#' && buffer[position - 1] != 'O') {
        buffer[position] = ' ';
        buffer[position - 1] = 'P';
    }
}

void move_bottom(char *buffer)
{
    int position = position_player(buffer);
    int i = number_columns(buffer);
    if (buffer[position + i] == 'X' && buffer[position + i + i] == 'X') {
    }
    else if (buffer[position + i] == 'X' && buffer[position + i + i] != '#') {
        buffer[position] = ' ';
        buffer[position + i] = 'P';
        buffer[position + i + i] = 'X';
    }
    else if (buffer[position + i] == 'X' && buffer[position + i + i] == '#') {
    }
    else if (buffer[position + i] != '#' && buffer[position + i] != 'O') {
        buffer[position] = ' ';
        buffer[position + i] = 'P';
    }
}

void move_top(char *buffer)
{
    int position = position_player(buffer);
    int i = number_columns(buffer);
    if (buffer[position - i] == 'X' && buffer[position - i - i] == 'X') {
    }
    else if (buffer[position - i] == 'X' && buffer[position - i - i] != '#') {
        buffer[position] = ' ';
        buffer[position - i] = 'P';
        buffer[position - i - i] = 'X';
    }
    else if (buffer[position - i] == 'X' && buffer[position - i - i] == '#') {
       }
    else if (buffer[position - i] != '#' && buffer[position - i] != 'O') {
        buffer[position] = ' ';
        buffer[position - i] = 'P';
    }
}

int check_movement(int check_input, char *buffer)
{
    if (check_input == KEY_RIGHT)
        move_right(buffer);
    if (check_input == KEY_LEFT)
        move_left(buffer);
    if (check_input == KEY_DOWN)
        move_bottom(buffer);
    if (check_input == KEY_UP)
        move_top(buffer);
    return (0);
}
