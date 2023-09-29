#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> R(n);
  for (int& r : R) {
    cin >> r;
  }
  int minElement = *min_element(R.begin(), R.end());
  int maxProfit = *max_element(R.begin(), R.end()) - minElement;
  cout << maxProfit << endl;
  return 0;
}