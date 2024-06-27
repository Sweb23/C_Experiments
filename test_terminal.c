#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to open a new terminal and run the printing command
void open_terminal_and_print(int mode) {
    char command[256];

    if (mode == 0) {
        snprintf(command, sizeof(command), "gnome-terminal -- bash -c 'while :; do echo -n \"0\"; echo -n \"1\"; sleep 1; done'");
    } else {
        snprintf(command, sizeof(command), "gnome-terminal -- bash -c 'while :; do echo -n \"$((RANDOM % 256))\"; sleep 1; done'");
    }

    system(command);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <number_of_windows> <mode (0 or 1)>\n", argv[0]);
        return 1;
    }

    int num_windows = atoi(argv[1]);
    int mode = atoi(argv[2]);

    if (mode != 0 && mode != 1) {
        fprintf(stderr, "Mode must be 0 or 1.\n");
        return 1;
    }

    for (int i = 0; i < num_windows; ++i) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            return 1;
        }

        if (pid == 0) {
            // Child process
            open_terminal_and_print(mode);
            exit(0);
        }
    }

    // Wait for all child processes to finish
    for (int i = 0; i < num_windows; ++i) {
        wait(NULL);
    }

    return 0;
}

