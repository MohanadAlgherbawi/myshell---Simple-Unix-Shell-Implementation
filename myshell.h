#ifndef MYSHELL_H
#define MYSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 64

void execute_command(char **args, int background);
void change_directory(char **args);
void clear_screen();
void list_directory(char **args);
void display_environment();
void echo_command(char **args);
void pause_shell();
void show_help();
void quit_shell();

struct builtin {
    char *name;
    void (*func)(char **);
};

extern struct builtin builtins[];  

#endif