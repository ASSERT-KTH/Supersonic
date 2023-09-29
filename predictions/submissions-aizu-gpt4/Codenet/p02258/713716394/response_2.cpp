#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> R(n);
  for (auto& val : R) {
    cin >> val;
  }
  int minPrice = R[0];
  int maxProfit = -2000000000;
  for (int i = 1; i < n; ++i) {
    maxProfit = max(maxProfit, R[i] - minPrice);
    minPrice = min(minPrice, R[i]);
  }
  cout << maxProfit << endl;
  return 0;
}