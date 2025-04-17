#include <stdio.h>
#include <stdlib.h>

int sum_file(FILE *fp){
  int sum = 0;
  int num;
  int quantity;
  int count = 0;
  if (fscanf(fp, "%d", &quantity) != 1) {
    printf("Error could not read quantity\n");
    return -1;
  }
  while (fscanf(fp, "%d", &num) == 1){
    sum += num;
    count++;
  }
  if (count != quantity){
    printf("Error: sum of numbers in file is not equal to the first number\n");
    return -1;
  }
  return sum;
}



int main(void){
  FILE *file = fopen("number_inputs.txt", "r");
  if (file == NULL){
    printf("File not found\n");
    return 0;
  }
  int sum = sum_file(file);
  if (sum == -1) {
    printf("Error reading file\n");
  } else {
    printf("Sum of numbers in file: %d\n", sum);
  }
  fclose(file);
  return 0;
}