#include <iostream>
#include <limits>
using namespace std;

int main() {
  int n;
  int maxProfit = std::numeric_limits<int>::min();
  int Ri = std::numeric_limits<int>::max();
  cin >> n;
  int R[n];
  for (int i = 0; i < n; ++i) {
    cin >> R[i];
  }
  for (int i = 0; i < n; ++i) {
    int diff = R[i] - Ri;
    if (diff > maxProfit) {
      maxProfit = diff;
      Ri = R[i];
    }
  }
  cout << maxProfit << endl;
  return 0;
}