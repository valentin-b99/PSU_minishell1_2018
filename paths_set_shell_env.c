/*
** EPITECH PROJECT, 2019
** paths_set_shell_env
** File description:
** paths_set_sell_env
*/

#include "include/minishell.h"

char **get_paths(char **env)
{
    int i = 0;

    while (my_strncmp(env[i], "PATH=", 4) != 0)
        i++;
    return (str_to_word_arr(env[i], 5));
}

void set_shell_env(list_t *l_env, char ***env, char *fname)
{
    size_t size;
    char *buff;

    if ((buff = malloc(sizeof(char) * 500)) == NULL)
        exit(84);
    buff = getcwd(buff, size);
    edit_elem(l_env, VAR_SHELL, my_strcat(buff, fname));
    set_list_to_env(l_env, env);
}