#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int n;
  cin >> n;
  int minVal = 2000000, maxVal = -2000000;
  int A[10001] = {};
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    A[t]++;
    minVal = min(minVal, t);
    maxVal = max(maxVal, t);
  }
  cout << minVal;
  for (int i = minVal + 1; i <= maxVal; i++) {
    for (int j = 0; j < A[i]; j++) {
      cout << ' ' << i;
    }
  }
  cout << endl;
  return 0;
}