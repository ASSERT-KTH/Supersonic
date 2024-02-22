#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> R(n);
  cin >> R[0];
  int maxProfit = 0;
  int Ri = R[0];
  for (int i = 1; i < n; i++) {
    cin >> R[i];
    if (R[i] - Ri > maxProfit) {
      maxProfit = R[i] - Ri;
    }
    if (R[i] < Ri) {
      Ri = R[i];
    }
  }
  cout << maxProfit << endl;
  return 0;
}