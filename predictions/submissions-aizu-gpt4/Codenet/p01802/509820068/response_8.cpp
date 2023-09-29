#include <iostream>
#include <cmath>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int d, e;
  while (1) {
    cin >> d >> e;
    if (d == 0 && e == 0)
      break;
    double min = 1e9;
    for (int i = 0; i <= d; ++i) {
        int j = d - i;
        double cost = sqrt(i * i + j * j);
        double gap = fabs(cost - e);
        if (gap < min) {
            min = gap;
        }
    }
    cout << min << "\n";
  }
  return 0;
}