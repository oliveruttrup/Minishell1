/*
** EPITECH PROJECT, 2024
** B-PSU-200-BAR-2-1-minishell1-oliver.uttrup
** File description:
** commands
*/

#include "../include/my.h"

void cmd_exit(info_t *info, char **env)
{
    (void)info;
    (void)env;
    exit(0);
}

void cmd_env(info_t *info, char **env)
{
    if (info->input_arr[1] == NULL)
        print_list(info);
    else {
        my_putstr_error("env: '");
        my_putstr_error(info->input_arr[1]);
        my_putstr_error("': No such file or directory\n");
    }
}

void delete_condition(info_t *info, node_t *temp, node_t *prev)
{
    if (prev == NULL) {
        info->head = temp->next;
    } else {
        prev->next = temp->next;
    }
}

static void list_len(info_t *info)
{
    node_t *temp = info->head;
    int i = 0;

    while (temp != NULL) {
        i++;
        temp = temp->next;
    }
}

static int input_len(info_t *info)
{
    int i = 0;

    while (info->input_arr[i] != NULL) {
        i++;
    }
    return i;
}

void cmd_setenv(info_t *info, char **env)
{
    int len = input_len(info);

    if (len > 3) {
        my_putstr_error("setenv: Too many arguments.\n");
        return;
    }
    if (info->input_arr[1] == NULL) {
        print_list(info);
        return;
    } else {
        insert_node(info);
    }
    return;
}

void cmd_unsetenv(info_t *info, char **env)
{
    node_t *temp = info->head;
    node_t *prev = NULL;
    int len = input_len(info);

    if (len == 1)
        return;
    while (temp != NULL) {
        if (my_strncmp(info->input_arr[1], temp->str,
            my_strlen(info->input_arr[1])) == 0) {
            delete_condition(info, temp, prev);
            free(temp->str);
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}
