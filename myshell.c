#include "myshell.h"


struct builtin builtins[] = {
    {"cd", change_directory},
    {"clr", clear_screen},
    {"dir", list_directory},
    {"environ", display_environment},
    {"echo", echo_command},
    {"help", show_help},
    {"pause", pause_shell},
    {"quit", quit_shell},
    {NULL, NULL}
};

int main(int argc, char *argv[]) {
    char line[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];
    int background;
    FILE *input_stream = stdin;

    if (argc == 2) {
        input_stream = fopen(argv[1], "r");
        if (input_stream == NULL) {
            perror("Error opening batch file");
            exit(EXIT_FAILURE);
        }
    }

    while (1) {
        background = 0;
        
        if (input_stream == stdin) {
            char cwd[1024];
            if (getcwd(cwd, sizeof(cwd)) != NULL) {
                printf("%s/myshell> ", cwd);
            } else {
                printf("myshell> ");
            }
        }

        if (fgets(line, sizeof(line), input_stream) == NULL) {
            if (input_stream != stdin) {
                fclose(input_stream);
                exit(EXIT_SUCCESS);
            }
            continue;
        }

        char *token = strtok(line, " \t\n");
        int i = 0;
        while (token != NULL && i < MAX_ARGS - 1) {
            if (strcmp(token, "&") == 0) {
                background = 1;
                break;
            }
            args[i++] = token;
            token = strtok(NULL, " \t\n");
        }
        args[i] = NULL;

        if (args[0] != NULL) {
            execute_command(args, background);
        }
    }

    return 0;
}

void execute_command(char **args, int background) {
    for (int i = 0; builtins[i].name != NULL; i++) {
        if (strcmp(args[0], builtins[i].name) == 0) {
            builtins[i].func(args);
            return;
        }
    }

    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
        perror("execvp failed");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork failed");
    } else {
        if (!background) {
            waitpid(pid, NULL, 0);
        }
    }
}