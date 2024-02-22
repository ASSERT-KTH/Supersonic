#include <stdio.h>

int main() {
  int inputSize, inputValue, sum = 0;
  int flagArray[999] = {0}; // Initialize array to 0

  // Read first set of inputs
  scanf("%d", &inputSize);
  for (; inputSize--; ) {
    scanf("%d", &inputValue);
    flagArray[inputValue] = 1;
  }

  // Read second set of inputs and calculate sum
  scanf("%d", &inputSize);
  for (; inputSize--; ) {
    scanf("%d", &inputValue);
    sum += flagArray[inputValue];
  }

  printf("%d\n", sum);
  return 0;
}