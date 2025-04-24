#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_gradebook(FILE *fp) {
    char surname[50];
    int marks[4];

    rewind(fp);

    while (fscanf(fp, "%49s", surname) == 1) {
        int sum = 0;

        for (int i = 0; i < 4; i++) {
            if (fscanf(fp, "%d", &marks[i]) != 1) {
                printf("Invalid format for %s\n", surname);
                return;
            }
            sum += marks[i];
        }

        float avg = (float)sum / 4;

        printf("%s average: %.2f\n", surname, avg);

        char filename[64];
        snprintf(filename, sizeof(filename), "%s.txt", surname);
        FILE *out = fopen(filename, "w");
        if (out == NULL) {
            printf("Error creating file: %s\n", filename);
            continue;
        }
        fprintf(out, "%s\n", surname);
        for (int i = 0; i < 4; i++) {
            fprintf(out, "%d ", marks[i]);
        }
        fclose(out);
    }
}

int main(void) {
    FILE *file = fopen("gradebook.txt", "r");
    if (file == NULL) {
        printf("File not found\n");
        return 1;
    }

    process_gradebook(file);

    fclose(file);
    return 0;
}



