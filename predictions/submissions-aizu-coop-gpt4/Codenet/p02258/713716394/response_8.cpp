#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> R(n);
  
  // Reading the elements
  for (auto &elem : R) {
    cin >> elem;
  }

  int maxProfit = 1 - 1000000000;
  int Ri = 2000000000;

  // Processing the elements
  for (const auto &elem : R) {
    maxProfit = max(maxProfit, elem - Ri);
    Ri = min(Ri, elem);
  }

  cout << maxProfit << endl;
  return 0;
}