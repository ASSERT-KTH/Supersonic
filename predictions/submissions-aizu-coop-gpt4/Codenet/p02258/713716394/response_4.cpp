#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  int maxProfit = 1 - 1000000000;
  int minPrice = 2000000000;
  cin >> n;
  vector<int> R(n);
  for (int i = 0; i < n; i++) {
    cin >> R[i];
  }
  for (int price : R) {
    maxProfit = max(maxProfit, price - minPrice);
    minPrice = min(minPrice, price);
  }
  cout << maxProfit << endl;
  return 0;
}