/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** my_str_isnum.c
*/

#include "../include/my.h"

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            i++;
        } else
            return 0;
    }
    return 1;
}
