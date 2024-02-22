#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int num1, num2, counter = 0;
  int maxNum = 0, inputNum;

  // Read first set of numbers and find the maximum number
  scanf("%d", &num1);
  int* checkArray = calloc(num1, sizeof(int)); // dynamically allocated to the maximum number
  for (int i = 0; i < num1; i++) {
    if(scanf("%d", &inputNum) != 1) {
      printf("Failed to read number\n");
      exit(1);
    }
    if(inputNum > maxNum) maxNum = inputNum;
    checkArray[inputNum] = 1;
  }

  // Resize the array to the maximum number
  checkArray = realloc(checkArray, (maxNum + 1) * sizeof(int));

  // Read second set of numbers and count matches
  scanf("%d", &num2);
  for (int i = 0; i < num2; i++) {
    if(scanf("%d", &inputNum) != 1) {
      printf("Failed to read number\n");
      exit(1);
    }
    counter += checkArray[inputNum];
  }

  printf("%d\n", counter);

  // Free dynamic memory
  free(checkArray);

  return 0;
}