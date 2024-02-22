#include <iostream>
using namespace std;
int main() {
  for (int i = 1; i <= 9; i++) {
    int running_total = i; // Initialize running total
    for (int j = 1; j <= 9; j++) {
      cout << i << "x" << j << "=" << running_total << '\n'; // Use '\n' instead of endl
      running_total += i; // Increment running total by i
    }
  }
  return 0;
}