#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  int maxProfit = 1 - 1000000000;
  int Ri = 2000000000;
  cin >> n;
  vector<int> R(n);
  vector<int>::iterator itr = R.begin();
  for (; itr != itrE; itr++) {
    cin >> *itr;
  }
  itr = R.begin();
  for (; itr != itrE; itr++) {
    if (maxProfit < *itr - Ri) {
      maxProfit = *itr - Ri;
    }
    if (*itr < Ri) {
      Ri = *itr;
    }
  }
  cout << maxProfit << endl;
  return 0;
}
