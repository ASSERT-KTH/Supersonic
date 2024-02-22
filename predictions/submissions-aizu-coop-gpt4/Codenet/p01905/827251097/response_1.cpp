#include <cstdio> // for scanf and printf

int main() {
  // Define two integers to hold the user's input.
  int firstNumber, secondNumber;

  // Read the two numbers from standard input.
  // Check the return value of scanf to ensure that two inputs were read.
  if (scanf("%d%d", &firstNumber, &secondNumber) != 2) {
    printf("Error: Expected two integers as input.\n");
    return 1; // Return an error code.
  }

  // Calculate the difference between the two numbers minus one.
  int differenceMinusOne = firstNumber - secondNumber - 1;

  // Print the result.
  printf("%d\n", differenceMinusOne);

  return 0; // Indicate that the program completed successfully.
}