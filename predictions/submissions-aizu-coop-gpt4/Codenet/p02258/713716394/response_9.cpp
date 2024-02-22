#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  int maxProfit = 1 - 1000000000;
  int Ri = 2000000000;

  for (int i = 0; i < n; i++) {
    int currentR;
    cin >> currentR;
    
    if (maxProfit < currentR - Ri) {
      maxProfit = currentR - Ri;
    }
    if (currentR < Ri) {
      Ri = currentR;
    }
  }

  cout << maxProfit << endl;
  return 0;
}