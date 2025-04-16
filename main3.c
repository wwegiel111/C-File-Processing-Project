#include <stdio.h>
#include <stdlib.h>

int rev_cpy_file(char *src_path, char *dest_path){
  FILE *src = fopen(src_path, "r");
  if (src == NULL){
    printf("Error opening file\n");
    return -1;
  }

  FILE *dest = fopen(dest_path, "w");
  if (dest == NULL){
    printf("Error opening file\n");
    fclose(src);
    return -1;
  }
  int bytes_cpy = 0;
  char c;
  while ((c = fgetc(src)) != EOF){
    if (fputc(c, dest) == EOF){
      fclose(dest);
      fclose(src);
    }
    bytes_cpy++;
  }
  fclose(src);
  fclose(dest);
  return bytes_cpy;
}

int main(void){
  char path[] = "test.txt";
  char dest_path[] = "test2.txt";
  if (rev_cpy_file(path, dest_path) == -1){
    printf("Error copying file\n");
  } else{
    printf("File copied\n");
    int byte_cpy = rev_cpy_file(path, dest_path);
    printf("File copied: bytes copied: %d\n", byte_cpy);
  }

}