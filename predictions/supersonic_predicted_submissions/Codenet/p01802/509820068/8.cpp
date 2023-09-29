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
    for (int i = 0; i <= d; i++)
      for (int j = i; j <= d; j++) {
        if (i + j == d) {
          double cost = sqrt(i * i + j * j);
          double gap = sqrt((cost - e) * (cost - e));
          if (gap < min) {
            min = gap;
          }
    }
    cout << min << endl;
  }
  return 0;
}
