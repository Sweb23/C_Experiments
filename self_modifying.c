#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    const char *source_file = __FILE__;  // __FILE__ contains the name of the current source file

    // Open the source file in append mode
    file = fopen(source_file, "a");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Append a comment to the source file
    fprintf(file, "\n// This comment was added by the program itself\n");
    fclose(file);

    printf("Source code modified successfully.\n");
    return 0;
}

