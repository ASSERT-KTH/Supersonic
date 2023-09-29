#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  int maxProfit = 1 - 1000000000;
  int Ri = 2000000000;
  cin >> n;
  vector<int> R(n);
  for (int i=0; i<n; i++) {
    cin >> R[i];
  }
  for (int i=0; i<n; i++) {
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