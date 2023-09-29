#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  
  vector<int> R(n);
  for (int i = 0; i < n; ++i) {
    cin >> R[i];
  }

  int maxProfit = R[1] - R[0];
  int minPrice = R[0];

  for (int i = 1; i < n; ++i) {
    maxProfit = max(maxProfit, R[i] - minPrice);
    minPrice = min(minPrice, R[i]);
  }
  
  cout << maxProfit << '\n';
  
  return 0;
}