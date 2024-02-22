#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
  int a = 0, b = 0;
  int *H = new int[100]; // Dynamically allocated memory for H
  int *W = new int[100]; // Dynamically allocated memory for W

  while (1) {
    cin >> H[a] >> W[a];
    if (H[a] == 0 && W[a] == 0)
      break;
    a++;
  }

  while (b < a) {
    int rectangleSize = H[b] * W[b]; // Calculate the size of the rectangle
    for (int i = 0; i < rectangleSize; i++) {
      printf("#");
      if ((i + 1) % W[b] == 0) { // Print a newline character after every W[b] characters
        printf("\n");
      }
    }
    b++;
    printf("\n");
  }

  delete[] H; // Deallocate dynamically allocated memory for H
  delete[] W; // Deallocate dynamically allocated memory for W

  return 0;
}