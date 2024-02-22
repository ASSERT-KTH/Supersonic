#include <iostream>
#include <vector>
using namespace std;
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  int maxProfit = 1 - 1000000000;
  cin >> n;
  vector<int> R(n);
  cin >> R[0];
  int Ri = R[0];
  for (int i = 1; i < n; i++) {
    cin >> R[i];
    if (maxProfit < R[i] - Ri) {
      maxProfit = R[i] - Ri;
    }
    if (R[i] < Ri) {
      Ri = R[i];
    }
  }
  cout << maxProfit << endl;
  return 0;
}