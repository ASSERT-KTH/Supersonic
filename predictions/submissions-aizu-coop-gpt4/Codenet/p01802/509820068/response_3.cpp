#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
int main() {
  int d, e;
  while (1) {
    cin >> d >> e;
    double min = 100000;
    if (d == 0 && e == 0)
      break;
    for (int i = 0; i <= d; i++) {
      int j = d - i; // Calculate 'j' based on 'i'
      double cost = sqrt(i * i + j * j); // Move inside the loop
      double gap = abs(cost - e); // Use abs() instead of sqrt() to calculate the gap
      if (gap < min) {
        min = gap;
      }
    }
    cout << min << endl;
  }
  return 0;
}