#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *source_file = __FILE__;
    char exe_file[256];

    // Get the path of the executable
    if (readlink("/proc/self/exe", exe_file, sizeof(exe_file) - 1) == -1) {
        perror("Error getting executable path");
        return 1;
    }
    exe_file[strlen(exe_file)] = '\0'; // Null-terminate the string

    // Delete the source file
    if (remove(source_file) == 0) {
        printf("I successfuly killed myself.\n");
    } else {
        perror("Couldn't find my gun.");
        return 1;
    }

    // Delete the executable file
    if (remove(exe_file) == 0) {
        printf("What was done cannot be undone.\n");
    } else {
        perror("I need more bullets!");
        return 1;
    }

    return 0;
}

