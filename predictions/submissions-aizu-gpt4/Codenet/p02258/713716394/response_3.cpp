#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  int maxProfit = INT_MIN;
  int Ri = INT_MAX;
  cin >> n;
  vector<int> R(n);
  for (int i = 0; i < n; ++i) {
    cin >> R[i];
  }
  for (int i = 0; i < n; ++i) {
    maxProfit = max(maxProfit, R[i] - Ri);
    Ri = min(Ri, R[i]);
  }
  cout << maxProfit << endl;
  return 0;
}