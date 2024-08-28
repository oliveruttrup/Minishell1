/*
** EPITECH PROJECT, 2024
** B-PSU-200-BAR-2-1-minishell1-oliver.uttrup
** File description:
** chdir
*/

#include "../include/my.h"

char *find_home(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], "HOME=", 5) == 0) {
            break;
        }
        i++;
    }
    return env[i] + 5;
}

void change_conditions(info_t *info, char *current_path)
{
    struct stat sb;

    stat(info->input_arr[1], &sb);
    if (info->input_arr[1] && access(info->input_arr[1], F_OK) != 0) {
        my_putstr_error(info->input_arr[1]);
        my_putstr_error(": No such file or directory.\n");
    } else if (info->input_arr[1] && access(info->input_arr[1], F_OK) == 0 &&
    !S_ISDIR(sb.st_mode)) {
        my_putstr_error(info->input_arr[1]);
        my_putstr_error(": Not a directory.\n");
    } else {
        chdir(info->input_arr[1]);
        free(info->old_pwd);
        info->old_pwd = current_path;
    }
}

void cmd_cd(info_t *info, char **env)
{
    char *home = find_home(env);
    char *current_path = getcwd(NULL, 0);

    if (info->input_arr[1] && my_strcmp(info->input_arr[1], "-") == 0) {
        chdir(info->old_pwd);
        free(info->old_pwd);
        info->old_pwd = current_path;
        return;
    }
    if (info->input_arr[1] == NULL ||
    my_strcmp(info->input_arr[1], "~") == 0) {
        chdir(home);
        free(info->old_pwd);
        info->old_pwd = current_path;
        return;
    }
    change_conditions(info, current_path);
}
