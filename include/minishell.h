/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#include "my.h"
#include "config.h"

#define TEST_EDIT_ELEM (str_array_len(arr_inputs) == 2) ? ("") : (arr_inputs[2])


typedef struct elem_s
{
    char *name;
    char *value;
    struct elem_s *next;
} elem_t;

typedef struct list_s
{
    int nb;
    struct elem_s *first;
} list_t;


/**
*? cmd_cd.c
*/
int cd_home(list_t *l_env);
int cd_rev(list_t *l_env, char ***env);
void cmd_cd(char **arr_inputs, list_t *l_env, char ***env);
void cmd_cd_next(char **arr_inputs, list_t *l_env, char ***env);

/**
*? cmd_exit.c
*/
int cmd_exit_next(char **arr_inputs, int *exit_val);
int cmd_exit(char **arr_inputs, int *exit_val);

/**
*? cmds.c
*/
int cmd_is_valid(char *cmd);
int search_valid_path(char ***arr_paths, char *cmd);
void other_cmds(char ***arr_inputs, char ***arr_paths, char ***env);
void my_cmds(char ***arr_inputs, char ***arr_paths, char ***env, list_t *l_env);

/**
*? env.c
*/
void display_env(char ***env);
int env_name_exist(list_t *list, char *name);

/**
*? epur_str.c
*/
int check_spaces_before(char *str);
void epur_str(char **str);

/**
*? fill_struct.c
*/
int name_len(char *str);
char *return_name(char *str);
void fill_struct(list_t *list, char **env);

/**
*? main.c
*/
int read_input(char ***env, list_t *l_env, char ***arr_paths, int *exit_val);
int my_shell(char **env, char *fname);

/**
*? manage_list.c
*/
void init_list(list_t *list);
void add_elem(list_t *list, char *name, char *value);
void rem_elem(list_t *list, char *name);
void edit_elem(list_t *list, char *name, char *value);

/**
*? mem_set.c
*/
void mem_set(char **str, int len);
void set_shell_env(list_t *l_env, char ***env, char *fname);

/**
*? paths_set_shell_env.c
*/
char **get_paths(char **env);

/**
*? print_error.c
*/
void print_error(char *cmd, int err);

/**
*? paths_set_shell_env.c
*/
char **get_paths(char **env);
void set_shell_env(list_t *l_env, char ***env, char *fname);

/**
*? prompt_format.c
*/
char *return_user(list_t *list);
char *parse_host(char *str);
char *return_host(list_t *list);
char *return_current_folder_next(list_t *list, elem_t *elem);
char *return_current_folder(list_t *list);

/**
*? prompt.c
*/
void my_putinv(char *str);
void prompt(list_t *l_env);

/**
*? setenv.c
*/
void set_list_to_env(list_t *l_env, char ***env);
int str_name_is_valid(char *str);
void made_set_env(char **arr_inputs, char ***env, list_t *l_env);
void set_env(char **arr_inputs, char ***env, list_t *l_env);

/**
*? str_array_len.c
*/
int str_array_len(char **arr);

/**
*? str_to_word_arr.c
*/
int count_words(char *str);
int len_word(char *str);
char **str_to_word_arr(char *str, int start);

/**
*? unsetenv.c
*/
void unset_env(char **arr_inputs, char ***env, list_t *l_env);

#endif /* !MATCHSTICK_H_ */
