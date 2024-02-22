#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> R;
  R.reserve(n);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    R.push_back(num);
  }
  int min_price = *min_element(R.begin(), R.end());
  int max_profit = *max_element(R.begin(), R.end()) - min_price;
  cout << max_profit << endl;
  return 0;
}