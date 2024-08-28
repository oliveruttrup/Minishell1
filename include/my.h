/*
** EPITECH PROJECT, 2023
** MY.H
** File description:
** task02
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <time.h>
    #include <pwd.h>
    #include <grp.h>
    #include <sys/wait.h>
    #include <stdbool.h>

typedef struct env_info_s {
    int env_rows;
} env_info_t;

typedef struct input_info_s {
    int i;
    int j;
    int k;
} input_info_t;

typedef struct node_s {
    char *str;
    struct node_s* next;
} node_t;

typedef struct info_s {
    char *full_path;
    char **path_arr;
    char *input;
    char **input_arr;
    char *tmp;
    node_t *head;
    char *old_pwd;
    bool exists;
    bool anum;
    char *cmd_path;
} info_t;

typedef struct commands_s {
    char *command;
    void (*func)(info_t *info, char **env);
} commands_t;

void my_putchar(char c);
int my_put_nbr(int nb);
int my_put_nbr_count(int nb, int *count);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strdup(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char *src);
int my_strncmp(const char *s1, const char *s2, int n);
int my_putstr_error(char const *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
bool is_alphanumeric(char *str);
bool char_is_alphanumeric(char character);

int main(int argc, char **argv, char **__environ);

char **string_to_array(char *str);
void print_arr(char **array);
char **input_string_to_array(char *str, input_info_t *info);
void print_list(info_t *info);

char *find_path(char **env);
char *clear_string(char *str);
char *search_cmd_path(char **path_arr, char *cmd);

void minishell(info_t *info, char **env, input_info_t *input_info);
void array_to_linked_list(char **arr, info_t *info);

void cmd_exit(info_t *info, char **env);

void cmd_cd(info_t *info, char **env);

void cmd_env(info_t *info, char **env);

void insert_node(info_t *info);
void cmd_setenv(info_t *info, char **env);

void cmd_unsetenv(info_t *info, char **env);

void free_array(char **arr);

#endif
