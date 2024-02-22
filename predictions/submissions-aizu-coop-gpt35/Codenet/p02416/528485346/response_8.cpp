#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  char* num = new char[1001]; // Change to dynamic memory allocation
  while (1) {
    scanf("%s", num);
    if (num[0] == '0')
      break;
    int sum = 0;
    int len = strlen(num); // Store the length of the number
    for (int i = 0; i < len; i++) {
      int digit = num[i] - '0'; // Compute the digit value once
      sum += digit;
    }
    printf("%d\n", sum);
  }
  delete[] num; // Free the dynamically allocated memory
  return 0;
}