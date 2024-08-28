/*
** EPITECH PROJECT, 2024
** B-PSU-200-BAR-2-1-minishell1-oliver.uttrup
** File description:
** input_str_arr
*/

#include "../include/my.h"

int input_rows_str(char *str)
{
    int rows = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] != ' ') {
            rows++;
        }
    }
    rows++;
    return rows;
}

char **input_init_array(char *str)
{
    int rows = input_rows_str(str);
    char **array = malloc((rows + 1) * sizeof(char *));

    if (array == NULL)
        return NULL;
    array[0] = malloc((50) * sizeof(char));
    return array;
}

char **input_conditions(char **array, char *str, input_info_t *info)
{
    if (str[info->k] == ' ' || str[info->k] == '\t') {
            if (info->j != 0) {
                array[info->i][info->j] = '\0';
                info->j = 0;
                info->i++;
                array[info->i] = malloc((50) * sizeof(char));
            }
        } else {
            array[info->i][info->j] = str[info->k];
            info->j++;
        }
}

char **input_string_to_array(char *str, input_info_t *info)
{
    char **array = input_init_array(str);

    info->i = 0;
    info->j = 0;
    for (info->k = 0; str[info->k] != '\0'; info->k++) {
        input_conditions(array, str, info);
    }
    if (info->j != 0) {
        array[info->i][info->j] = '\0';
        info->i++;
    }
    array[info->i] = NULL;
    return array;
}
