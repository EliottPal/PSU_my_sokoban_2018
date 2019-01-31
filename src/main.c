/*
** EPITECH PROJECT, 2018
** main
** File description:
** main function for my_sokoban
*/


#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "../inc/sokoban.h"

void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    map file representing the warehouse map,");
    my_putstr("containing '#' for walls, ");
    my_putstr("P' for the player, 'X' for boxes and");
    my_putstr("'0' for storage locations.\n");

    return;
}

int check_map(char const *filepath)
{
    int counter = 0;
    int i = 0;
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * (200 + 1));

    read(fd, buffer, 200);
    while (buffer[counter] != '\0') {
        if (buffer[counter] != '#' && buffer[counter] != ' '
            && buffer[counter] != 'X'&& buffer[counter] != 'O'
            && buffer[counter] != 'P' && buffer[counter] != '\n')
            i++;
        counter++;
    }
    close(fd);
    free(buffer);
    return (i);
}

int check_error(int ac, char **av)
{
    if (ac > 2) {
        my_putstr("Too much argument\n");
        return (84);
    }
    if (ac < 2) {
        my_putstr("Not enough arguments\n");
        return (84);
    }
    else
        return (0);
}

int main(int ac, char **av)
{
    int try_open = open(av[1], O_RDONLY);
    check_error(ac, av);

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return (0);
    }
    if (try_open == -1) {
        my_putstr("Can't open map\n");
        return (84);
    }
    else if (ac == 2) {
        if (check_map(av[1]) != 0) {
            my_putstr("Invalid map\n");
            return(84);
        }
        else
            print_map(av[1]);
    }
}
