/*
** EPITECH PROJECT, 2018
** print_map
** File description:
** print map for sokoban
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include "../inc/sokoban.h"

int print_map(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * (200 + 1));
    endwin();
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    read(fd, buffer, 200);
    while (1) {
        clear();
        printw("%s", buffer);
        int check_arguments = getch();
        check_movement(check_arguments, buffer);
        check_loose(buffer);
        if (check_arguments == ' ') {
            endwin();
            close(fd);
            free(buffer);
            print_map(filepath);
        }
        if (number_storage(buffer) == 0) {
            endwin();
            close(fd);
            free(buffer);
            return (0);
        }
        refresh();
    }
}
