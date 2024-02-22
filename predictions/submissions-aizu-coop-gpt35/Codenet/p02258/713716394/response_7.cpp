#include <iostream>
using namespace std;

int main() {
  int n;
  int maxProfit = 1 - 1000000000;
  int Ri = 2000000000;
  cin >> n;

  int R;
  for (int i = 0; i < n; i++) {
    cin >> R;
    int profit = R - Ri;
    if (maxProfit < profit) {
      maxProfit = profit;
    }
    if (R < Ri) {
      Ri = R;
    }
  }

  cout << maxProfit << endl;
  return 0;
}