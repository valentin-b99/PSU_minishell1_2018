/*
** EPITECH PROJECT, 2019
** cmd_exit
** File description:
** cmd_exit
*/

#include "include/minishell.h"

int cmd_exit_next(char **arr_inputs, int *exit_val)
{
    if (str_array_len(arr_inputs) < 3 && my_str_isnum(arr_inputs[1])) {
        if (isatty(0))
            my_putstr("exit");
        *exit_val = my_getnbr(arr_inputs[1]);
        return (1);
    } else {
        my_puterror(arr_inputs[0]);
        my_puterror(ERR_EXPR_SYNTAX);
        return (0);
    }
}

int cmd_exit(char **arr_inputs, int *exit_val)
{
    if (!my_strcmp(arr_inputs[0], CMD_EXIT)) {
        if (str_array_len(arr_inputs) > 1) {
            return (cmd_exit_next(arr_inputs, exit_val));
        } else {
            if (isatty(0))
                my_putstr("exit");
            return (1);
        }
    }
    return (0);
}