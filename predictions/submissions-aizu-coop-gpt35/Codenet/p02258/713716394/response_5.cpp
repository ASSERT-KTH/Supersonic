#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> R;
  R.reserve(n);

  int maxProfit;
  int Ri;

  cin >> Ri;
  maxProfit = Ri;

  for (int i = 1; i < n; i++) {
    int num;
    cin >> num;

    R.push_back(num);

    if (num - Ri > maxProfit) {
      maxProfit = num - Ri;
    }
    if (num < Ri) {
      Ri = num;
    }
  }

  cout << maxProfit << endl;
  return 0;
}