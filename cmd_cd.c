/*
** EPITECH PROJECT, 2019
** cmd_cd
** File description:
** cmd_cd
*/

#include "include/minishell.h"

int cd_home(list_t *l_env)
{
    elem_t *elem = l_env->first;

    while (elem) {
        if (!my_strcmp(elem->name, VAR_HOME)) {
            chdir(elem->value);
            return (1);
        }
        elem = elem->next;
    }
    return (0);
}

int cd_rev(list_t *l_env, char ***env)
{
    elem_t *elem = l_env->first;
    size_t size;
    char *buff;
    char *oldpwd;

    if ((buff = malloc(sizeof(char) * 300)) == NULL)
        exit(84);
    oldpwd = getcwd(buff, size);
    while (elem) {
        if (!my_strcmp(elem->name, VAR_OLDPWD)) {
            chdir(elem->value);
            edit_elem(l_env, VAR_OLDPWD, oldpwd);
            return (1);
        }
        elem = elem->next;
    }
    return (0);
}

void cmd_cd_next(char **arr_inputs, list_t *l_env, char ***env)
{
    size_t size;
    char *buff;
    int state = 0;

    if ((buff = malloc(sizeof(char) * 300)) == NULL)
        exit(84);
    if (!my_strcmp(arr_inputs[1], CMD_CD_REV))
        state = cd_rev(l_env, env);
    if (!state && !access(arr_inputs[1], R_OK))
        edit_elem(l_env, VAR_OLDPWD, getcwd(buff, size));
    if (!my_strcmp(arr_inputs[1], CMD_CD_HOME_1) ||
        !my_strcmp(arr_inputs[1], CMD_CD_HOME_2))
        state = cd_home(l_env);
    if (!state && chdir(arr_inputs[1]))
        print_error(arr_inputs[1], errno);
    free(buff);
}

void cmd_cd(char **arr_inputs, list_t *l_env, char ***env)
{
    size_t size;
    char *buff;

    if (str_array_len(arr_inputs) > 2) {
        my_putstr(arr_inputs[0]);
        my_puterror(ERR_TO_MANY_ARGS);
        return;
    }
    if ((buff = malloc(sizeof(char) * 300)) == NULL)
        exit(84);
    if (str_array_len(arr_inputs) < 2) {
        edit_elem(l_env, VAR_OLDPWD, getcwd(buff, size));
        cd_home(l_env);
    } else {
        cmd_cd_next(arr_inputs, l_env, env);
    }
    edit_elem(l_env, VAR_PWD, getcwd(buff, size));
    set_list_to_env(l_env, env);
    free(buff);
}