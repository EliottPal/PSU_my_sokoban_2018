/*
** EPITECH PROJECT, 2018
** sokoban.h
** File description:
** prototypes for sokoban
*/


#ifndef SOKOBAN_H_
#define SOKOBAN_H_

int my_strlen(char const *str);
void my_putchar(char c);
int my_putstr(char *str);
int position_player(char *buffer);
int number_columns(char *buffer);
void move_right(char *buffer);
void move_left(char *buffer);
void move_bottom(char *buffer);
void move_top(char *buffer);
int check_movement(int check_input, char *buffer);
int print_map(char const *filepath);
void help(void);
int check_map(char const *filepath);
int check_error(int ac, char **av);
int number_storage(char*buffer);
int *position_storage(char *buffer);
void reprint_storage(char* buffer);
int number_boxes(char *buffer);
int *position_boxes(char *buffer);
int check_loose(char *buffer);

#endif
