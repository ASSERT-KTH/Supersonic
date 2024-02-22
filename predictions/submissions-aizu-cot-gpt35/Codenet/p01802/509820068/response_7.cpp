#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
  int d, e;
  while (1) {
    cin >> d >> e;
    if (d == 0 && e == 0)
      break;

    int minGap = d; // Initialize minGap to maximum possible value

    for (int i = 0; i <= d / 2; i++) {
      int j = d - i;
      int gap = abs(i * i + j * j - e * e); // Calculate the gap using integer arithmetic

      if (gap < minGap) {
        minGap = gap;
      }
    }

    cout << sqrt(minGap) << endl; // Print the square root of minGap

  }
  return 0;
}