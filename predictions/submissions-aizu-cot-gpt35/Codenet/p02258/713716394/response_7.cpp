#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  int maxProfit = INT_MIN; // Initialize maxProfit to negative infinity
  int Ri = INT_MAX; // Initialize Ri to positive infinity
  cin >> n;
  vector<int> R(n);
  for (int i = 0; i < n; i++) {
    cin >> R[i];
    maxProfit = max(maxProfit, R[i] - Ri); // Update maxProfit if current profit is higher
    Ri = min(Ri, R[i]); // Update Ri if current element is smaller
  }
  cout << maxProfit << endl;
  return 0;
}