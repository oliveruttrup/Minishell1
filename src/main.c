/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** print_file
*/

#include "../include/my.h"

void print_arr(char **arr)
{
    int i = 0;

    while (arr[i] != NULL) {
        my_putstr(arr[i]);
        my_putchar('\n');
        i++;
    }
}

input_info_t *init_struct(input_info_t *info)
{
    info->i = 0;
    info->j = 0;
    info->k = 0;
    return info;
}

int main(int argc, char **argv, char **env)
{
    info_t *info = malloc(sizeof(info_t));
    input_info_t *input_info = malloc(sizeof(input_info_t));

    info->head = NULL;
    array_to_linked_list(env, info);
    init_struct(input_info);
    info->full_path = find_path(env);
    info->path_arr = string_to_array(info->full_path);
    minishell(info, env, input_info);
}
    // free_array(path_arr);
    // free(full_path);
