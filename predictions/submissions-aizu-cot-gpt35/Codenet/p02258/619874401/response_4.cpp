#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int maxDifference = 0;
  int currentMin;
  cin >> currentMin;
  for (int i = 1; i < n; i++) {
    int currentNumber;
    cin >> currentNumber;
    maxDifference = max(maxDifference, currentNumber - currentMin);
    currentMin = min(currentMin, currentNumber);
  }
  cout << maxDifference << endl;
  return 0;
}