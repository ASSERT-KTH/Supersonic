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
      int j = d - i;  // Calculate j directly
      double cost = sqrt(i * i + j * j);  // Move calculation outside the loop
      double gap = sqrt((cost - e) * (cost - e));
      if (gap < min) {
        min = gap;
      }
    }
    cout << min << '\n';  // Replace std::endl with '\n'
  }
  return 0;
}