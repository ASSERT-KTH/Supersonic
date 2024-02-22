#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  int maxProfit = 1 - 1000000000;
  int Ri = 2000000000;
  cin >> n;
  vector<int> R(n);
  // Using an integer index instead of an iterator
  for (int i = 0; i < n; i++) {
    cin >> R[i];
  }
  // Using an integer index instead of an iterator
  for (int i = 0; i < n; i++) {
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