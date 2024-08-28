/*
** EPITECH PROJECT, 2024
** B-PSU-200-BAR-2-1-minishell1-oliver.uttrup
** File description:
** copy_env
*/

#include "../include/my.h"

void print_list(info_t *info)
{
    node_t *temp = info->head;

    while (temp != NULL) {
        my_putstr(temp->str);
        my_putchar('\n');
        temp = temp->next;
    }
}

void free_list(info_t *info)
{
    node_t *temp;

    while (info->head != NULL) {
        temp = info->head;
        info->head = info->head->next;
        free(temp->str);
        free(temp);
    }
}

node_t *create_node_env(char *str)
{
    node_t *newNode = malloc(sizeof(node_t));

    if (newNode == NULL) {
        return NULL;
    }
    newNode->str = malloc(strlen(str) + 1);
    if (newNode->str == NULL) {
        return NULL;
    }
    newNode->str = my_strcpy(newNode->str, str);
    newNode->next = NULL;
    return newNode;
}

void insert_at_end(info_t *info, char *str)
{
    node_t *newNode = create_node_env(str);
    node_t *temp = info->head;

    if (info->head == NULL) {
        info->head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void array_to_linked_list(char **arr, info_t *info)
{
    int i = 0;

    while (arr[i] != NULL) {
        insert_at_end(info, arr[i]);
        i++;
    }
}
