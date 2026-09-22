#include <stdio.h>

int main() {
    FILE *file;

    file = fopen("data.txt", "w");

    if (file == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    fprintf(file, "This is a File I/O example in C.\n");

    fclose(file);

    printf("Data written successfully.\n");

    return 0;
}