/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "include/minishell.h"

int read_input(char ***env, list_t *l_env, char ***arr_paths, int *exit_val)
{
    size_t len = 0;
    char *input;
    char **arr_inputs;

    prompt(l_env);
    if (getline(&input, &len, stdin) == -1) {
        my_putstr("exit");
        return (0);
    }
    if ((arr_inputs = malloc(sizeof(char *) * (count_words(input) + 1))) ==
        NULL)
        exit(84);
    epur_str(&input);
    arr_inputs = str_to_word_arr(input, 0);
    if (cmd_exit(arr_inputs, exit_val))
        return (0);
    my_cmds(&arr_inputs, arr_paths, env, l_env);
    other_cmds(&arr_inputs, arr_paths, env);
    free(arr_inputs);
    return (1);
}

int my_shell(char **env, char *fname)
{
    char **arr_paths = get_paths(env);
    list_t *l_env;
    int exit_val = 0;

    if ((l_env = malloc(sizeof(list_t))) == NULL)
        exit(84);
    fill_struct(l_env, env);
    set_shell_env(l_env, &env, fname);
    while (1) {
        if (!read_input(&env, l_env, &arr_paths, &exit_val)) {
            free(l_env);
            my_putinv("\n");
            return (exit_val);
        }
    }
}

int main(int ac, char **av, char **env)
{
    if (ac != 1)
        return (84);
    if (str_array_len(env) < 1)
        return (84);
    return (my_shell(env, av[0] + 1));
}
