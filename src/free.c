/*
** EPITECH PROJECT, 2024
** B-PSU-200-BAR-2-1-minishell1-oliver.uttrup
** File description:
** free
*/

#include "../include/my.h"

void free_array(char **arr)
{
    int i = 0;

    while (arr[i] != NULL) {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void free_everything(struct info_s *info)
{
    free_array(info->input_arr);
    free(info->input);
    free_array(info->path_arr);
    free(info->full_path);
}
