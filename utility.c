#include "myshell.h"

void list_directory(char **args) {
    DIR *dir;
    struct dirent *entry;
    const char *path = args[1] ? args[1] : ".";

    if ((dir = opendir(path)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            printf("%s\n", entry->d_name);
        }
        closedir(dir);
    } else {
        perror("dir");
    }
}

void show_help() {
    const char *help_text = 
        "myshell - A simple shell implementation\n"
        "Internal commands:\n"
        "  cd [dir]     - Change directory\n"
        "  clr          - Clear screen\n"
        "  dir [dir]    - List directory contents\n"
        "  environ      - List environment variables\n"
        "  echo [text]  - Display text\n"
        "  help         - Show this help\n"
        "  pause        - Pause shell\n"
        "  quit         - Quit shell\n";
    
    printf("%s", help_text);
}

void quit_shell() {
    exit(EXIT_SUCCESS);
}

void pause_shell() {
    printf("Shell paused. Press Enter to continue...");
    while (getchar() != '\n');
}

void change_directory(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "cd: missing argument\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("cd");
        }
    }
}

void clear_screen() {
    system("clear");
}

void display_environment() {
    extern char **environ;
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }
}

void echo_command(char **args) {
    for (int i = 1; args[i] != NULL; i++) {
        printf("%s ", args[i]);
    }
    printf("\n");
}