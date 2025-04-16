#include <stdio.h>

int main(void) {
    char path[255];
    printf("Please enter the path: ");
    scanf("%s", path);

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("File not found\n");
        return 0;
    }

    char c;
    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }
    fclose(file);
    return 0;
}