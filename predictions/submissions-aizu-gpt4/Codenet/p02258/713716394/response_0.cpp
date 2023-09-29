#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> R(n);
  for (auto& r : R) {
    cin >> r;
  }

  int maxProfit = INT_MIN;
  int Ri = R[0];

  for (const auto& r : R) {
    maxProfit = max(maxProfit, r - Ri);
    Ri = min(Ri, r);
  }

  cout << maxProfit << endl;

  return 0;
}