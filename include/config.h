/*
** EPITECH PROJECT, 2019
** config
** File description:
** config
*/

#ifndef CONFIG_H_
#define CONFIG_H_

#define STR_BTW_NAME_VAL "="
#define CHR_BTW_NAME_VAL_DEF '='

#define CMD_EXIT "exit"
#define CMD_ENV "env"
#define CMD_SETENV "setenv"
#define CMD_UNSETENV "unsetenv"
#define CMD_CD "cd"
#define CMD_CD_REV "-"
#define CMD_CD_HOME_1 "~"
#define CMD_CD_HOME_2 "--"

#define CHR_SEP_1 ':'
#define CHR_SEP_2 ' '
#define CHR_SEP_3 '\n'

#define ERR_SETENV ": Too many arguments.\n"
#define ERR_UNSETENV ": Too few arguments.\n"
#define ERR_CMDNFOUND ": Command not found.\n"
#define ERR_SEGFAULT "Segmentation fault\n"
#define ERR_TO_MANY_ARGS ": Too many arguments.\n"
#define ERR_FLOATINGEX "Floating exception\n"
#define ERR_VAR_ALPHA ": Variable name must contain alphanumeric characters.\n"
#define ERR_VAR_BEGIN_LETTER ": Variable name must begin with a letter.\n"
#define ERR_EXPR_SYNTAX ": Expression Syntax.\n"

#define VAR_SHELL "SHELL"
#define VAR_HOME "HOME"
#define VAR_PWD "PWD"
#define VAR_OLDPWD "OLDPWD"
#define VAR_USER "USER"
#define VAR_HOST "HOST"

#endif /* !CONFIG_H_ */
