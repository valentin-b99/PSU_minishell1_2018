/*
** EPITECH PROJECT, 2019
** str_to_word_arr
** File description:
** str_to_word_arr
*/

#include "include/minishell.h"

int count_words(char *str)
{
    int nb = 1;

    for (int i = 0; str[i]; i++)
        if (str[i] == CHR_SEP_1 || str[i] == CHR_SEP_2 || str[i] == CHR_SEP_3)
            nb++;
    return (nb);
}

int len_word(char *str)
{
    int i = 0;

    while (str[i] && str[i] != CHR_SEP_1 && str[i] != CHR_SEP_2 &&
        str[i] != CHR_SEP_3)
        i++;
    return (i);
}

char **str_to_word_arr(char *str, int start)
{
    char **arr;
    int col = 0;

    if ((arr = malloc(sizeof(char *) * (count_words(str) + 1))) == NULL)
        exit(84);
    for (int i = start; i < my_strlen(str + start); i++) {
        if ((arr[col] = malloc(sizeof(char) * (len_word(str + i) + 1))) == NULL)
            exit(84);
        arr[col] = my_strncpy(arr[col], str + i, len_word(str + i));
        i += len_word(str + i);
        col++;
    }
    arr[col] = NULL;
    return (arr);
}