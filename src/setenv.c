/*
** EPITECH PROJECT, 2024
** B-PSU-200-BAR-2-1-minishell1-oliver.uttrup
** File description:
** setenv
*/

#include "../include/my.h"

bool check_path(info_t *info)
{
    node_t *temp = info->head;

    while (temp != NULL) {
        if (my_strncmp(info->input_arr[1], temp->str,
        my_strlen(info->input_arr[1])) == 0) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

node_t *setenv_conditions(info_t *info, node_t *newNode, bool exists)
{
    if (info->input_arr[2] == NULL && exists == false) {
        newNode->str = malloc(strlen(info->input_arr[1]) + 2);
        newNode->str = my_strcpy(newNode->str, info->input_arr[1]);
        newNode->str = my_strcat(newNode->str, "=");
    }
    if (info->input_arr[2] != NULL && exists == false) {
        newNode->str = malloc(strlen(info->input_arr[1]) +
        my_strlen(info->input_arr[2]) + 2);
        newNode->str = my_strcpy(newNode->str, info->input_arr[1]);
        newNode->str = my_strcat(newNode->str, "=");
        newNode->str = my_strcat(newNode->str, info->input_arr[2]);
    }
    return newNode;
}

void change_path(info_t *info, node_t *temp)
{
    while (temp != NULL) {
        if (my_strncmp(info->input_arr[1], temp->str,
        my_strlen(info->input_arr[1])) == 0) {
            free(temp->str);
            temp->str = malloc(strlen(info->input_arr[1]) +
            my_strlen(info->input_arr[2]) + 2);
            temp->str = my_strcpy(temp->str, info->input_arr[1]);
            temp->str = my_strcat(temp->str, "=");
            temp->str = my_strcat(temp->str, info->input_arr[2]);
            break;
        }
        temp = temp->next;
    }
}

static void print_env_error(info_t *info)
{
    if (info->input_arr[1] != NULL &&
    (char_is_alphanumeric(info->input_arr[1][0]) == false)) {
        my_putstr_error("setenv: Variable name must begin with a letter.\n");
        return;
    } else if (is_alphanumeric(info->input_arr[1]) == false) {
        my_putstr_error("setenv: Variable name must contain");
        my_putstr_error(" alphanumeric characters.\n");
    }
}

node_t *create_node(info_t *info, node_t *newNode)
{
    node_t *temp = info->head;

    if (newNode == NULL || is_alphanumeric(info->input_arr[1]) == false) {
        print_env_error(info);
        return NULL;
    }
    info->exists = check_path(info);
    newNode = setenv_conditions(info, newNode, info->exists);
    if (info->input_arr[2] == NULL && info->exists == true)
        return NULL;
    if (info->input_arr[2] != NULL && info->exists == true) {
        temp = info->head;
        change_path(info, temp);
        return NULL;
    }
    newNode->next = NULL;
    return newNode;
}

void insert_node(info_t *info)
{
    node_t *newNode = malloc(sizeof(node_t));
    node_t *temp = info->head;

    newNode = create_node(info, newNode);
    if (newNode == NULL)
        return;
    if (info->head == NULL) {
        info->head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
