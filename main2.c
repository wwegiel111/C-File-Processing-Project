#include <stdio.h>
#include <stdlib.h>

int size_file(FILE *fp){
    if (fp == NULL) {
        printf("File not found\n");
        return 0;
    } else {
        fseek(fp, 0, SEEK_END);
        int size = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        return size;
    }
}




int main(void) {
    FILE *file = fopen("test.txt", "r");
    size_file(file);
    printf("File size: %d\n", size_file);
    fclose(file);
    return 0;
}