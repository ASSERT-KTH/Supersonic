#include <iostream>
#include <vector>

int main() {
  int n;
  while (scanf("%d", &n) == 1 && n) { // 2. Optimized reading of 'n'
    std::vector<int> d(256, 0); // 1. Efficient data structure

    // Read 'a' and 'b', calculate differences, and update 'd'
    for (; n--; ) {
      char a, b;
      scanf(" %c %c", &a, &b); // Read characters 'a' and 'b'

      d[a] = b - a; // Calculate difference and update 'd'
    }

    // Read 'n' and print characters based on differences stored in 'd'
    for (; n--; ) {
      char a;
      scanf(" %c", &a); // Read character 'a'

      putchar(a + d[a]); // Print character based on difference stored in 'd'
    }

    putchar('\n'); // Print newline after each iteration
  }

  return 0;
}