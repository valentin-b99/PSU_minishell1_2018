/*
** EPITECH PROJECT, 2019
** print_error
** File description:
** print_error
*/

#include "include/minishell.h"

void print_error(char *cmd, int err)
{
    my_putstr(cmd);
    my_putstr(": ");
    my_putstr(strerror(err));
    if (err == ENOEXEC)
        my_putstr(". Wrong Architecture");
    my_putstr(".\n");
    
}