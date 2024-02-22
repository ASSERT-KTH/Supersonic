#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> R;
  R.reserve(n); // Reserve memory for n elements

  int firstElement;
  cin >> firstElement;
  R.push_back(firstElement);
  int maxProfit = 0;
  int Ri = firstElement;

  for (int i = 1; i < n; i++) {
    int price;
    cin >> price;
    R.push_back(price);

    if (price < Ri) {
      Ri = price;
    }

    int profit = price - Ri;
    if (profit > maxProfit) {
      maxProfit = profit;
    }
  }

  cout << maxProfit << endl;

  return 0;
}