#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  int maxProfit = INT_MIN;
  int minVal = INT_MAX;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    if (i != 0) {
      maxProfit = max(maxProfit, num - minVal);
    }
    minVal = min(minVal, num);
  }
  cout << maxProfit << endl;
  return 0;
}