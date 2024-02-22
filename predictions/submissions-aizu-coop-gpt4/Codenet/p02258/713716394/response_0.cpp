#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> R(n);

  for (int& element : R) {
    cin >> element;
  }

  int maxProfit = numeric_limits<int>::min();
  int minRi = numeric_limits<int>::max();

  for (const int& element : R) {
    maxProfit = max(maxProfit, element - minRi);
    minRi = min(minRi, element);
  }

  cout << maxProfit << endl;
  return 0;
}