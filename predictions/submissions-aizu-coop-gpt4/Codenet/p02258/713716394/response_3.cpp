#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); // Turn off synchronization with C standard libraries
  int n;
  cin >> n;
  int maxProfit = INT_MIN;
  int Ri = INT_MAX;
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (i != 0) {
      if (maxProfit < temp - Ri) {
        maxProfit = temp - Ri;
      }
    }
    if (temp < Ri) {
      Ri = temp;
    }
  }
  cout << maxProfit << endl;
  return 0;
}