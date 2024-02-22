#include <stdio.h>
#include <stdlib.h>

int main() {
  int sequenceLength, i, temp, maxSubsequenceLength = 0;
  int currentNum;
  
  scanf("%d", &sequenceLength);
  
  int* sequence = (int*) malloc((sequenceLength + 1) * sizeof(int));
  int* subsequenceLength = (int*) malloc((sequenceLength + 1) * sizeof(int));
  
  for (i = 1; i <= sequenceLength; i++) {
    scanf("%d", &sequence[i]);
    subsequenceLength[i] = 0; // Initializing the subsequenceLength array to 0
  }

  // Reading inputs for the subsequence search
  while(scanf("%d", &currentNum) == 1) {
    // Looping through the sequence to find the subsequence
    for (i = 1, temp = 0; i <= sequenceLength; temp = subsequenceLength[i], i++) {
      if (currentNum == sequence[i]) {
        subsequenceLength[i] = temp + 1;
      } else if (subsequenceLength[i] < temp) {
        subsequenceLength[i] = temp;
      }
      // Updating the maximum subsequence length
      if (subsequenceLength[i] > maxSubsequenceLength)
        maxSubsequenceLength = subsequenceLength[i];
    }
  }
  
  printf("%d\n", maxSubsequenceLength);

  // Resetting maxSubsequenceLength
  maxSubsequenceLength = 0;

  // Releasing the allocated memory
  free(sequence);
  free(subsequenceLength);

  return 0;
}