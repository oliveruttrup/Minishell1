/*
** EPITECH PROJECT, 2024
** B-PSU-200-BAR-2-1-minishell1-oliver.uttrup
** File description:
** search_path
*/

#include "../include/my.h"

char *find_path(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            break;
        }
        i++;
    }
    return env[i] + 5;
}

char *clear_string(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        str[i] = '\0';
        i++;
    }
    return str;
}

char *search_cmd_path(char **path_arr, char *cmd)
{
    int j = 0;
    char *tmp = malloc(sizeof(char) * 100);

    tmp = clear_string(tmp);
    while (path_arr[j] != NULL) {
        tmp = my_strcat(tmp, path_arr[j]);
        tmp = my_strcat(tmp, "/");
        tmp = my_strcat(tmp, cmd);
        if (access(tmp, F_OK) == 0) {
            return tmp;
        }
        tmp = clear_string(tmp);
        j++;
    }
    return cmd;
}
