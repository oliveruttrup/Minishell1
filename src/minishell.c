/*
** EPITECH PROJECT, 2024
** B-PSU-200-BAR-2-1-minishell1-oliver.uttrup
** File description:
** minishell
*/

#include "../include/my.h"

static const commands_t commands[] =
{
    {"exit", &cmd_exit},
    {"cd", &cmd_cd},
    {"env", &cmd_env},
    {"setenv", &cmd_setenv},
    {"unsetenv", &cmd_unsetenv}
};

static void cmd_conditions(info_t *info, struct stat *fileStat,
    int ex_ret, char **env)
{
    if (info->cmd_path != NULL && stat(info->cmd_path, fileStat) == 0 &&
    fileStat->st_mode & S_IXUSR) {
        ex_ret = execve(info->cmd_path, info->input_arr, env);
    } else {
        if (access(info->cmd_path, F_OK) != -1) {
            my_putstr_error(info->input_arr[0]);
            my_putstr_error(": Permission denied.\n");
        } else {
            my_putstr_error(info->input_arr[0]);
            my_putstr_error(": Command not found.\n");
        }
    }
    exit(ex_ret);
}

void basic_shell(info_t *info, char **env)
{
    int status = 0;
    pid_t pid;
    int ex_ret;
    struct stat fileStat;

    info->cmd_path = search_cmd_path(info->path_arr, info->input_arr[0]);
    pid = fork();
    if (pid == 0) {
        cmd_conditions(info, &fileStat, ex_ret, env);
    } else {
        waitpid(pid, &status, 0);
    }
}

void execute_cmd(info_t *info, char **env)
{
    int status = 0;

    for (int i = 0; i < 5; i++) {
        if (my_strcmp(commands[i].command, info->input_arr[0]) == 0) {
            commands[i].func(info, env);
            return;
        }
    }
    basic_shell(info, env);
}

void current_location(void)
{
    char *path = getcwd(NULL, 0);

    my_putchar('[');
    my_putstr(path);
    my_putstr("]$ ");
    free(path);
}

void minishell(info_t *info, char **env, input_info_t *input_info)
{
    size_t size = 0;
    int rd;

    info->input = NULL;
    while (1) {
        current_location();
        if (getline(&info->input, &size, stdin) == -1) {
            my_putchar('\n');
            exit(0);
        }
        if (my_strlen(info->input) == 1) {
            continue;
        }
        info->input[my_strlen(info->input) - 1] = '\0';
        info->input_arr = input_string_to_array(info->input, input_info);
        execute_cmd(info, env);
    }
}

// man waitpid
// hay una func autorizada que al parecer facilita el error handling
