#include <iostream>
#include <algorithm>
using namespace std;

int Input(const int n) {
  int maxWeight = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    maxWeight = max(maxWeight, w);
    sum += w;
  }
  return max(maxWeight, (sum + n - 1) / n);
}

bool IsAllLoaded(int P, int maxWeight, int sum, int n) {
  if (maxWeight > P) {
    return false;
  }
  int trackIndex = 0;
  int currentSum = 0;
  for (int i = 0; i < n; i++) {
    if (currentSum + sum > P) {
      trackIndex++;
      if (trackIndex == n) {
        return false;
      }
      currentSum = 0;
    }
    currentSum += sum;
  }
  return true;
}

int Calc(int n) {
  int maxWeight = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    maxWeight = max(maxWeight, w);
    sum += w;
  }
  int P = max(maxWeight, (sum + n - 1) / n);
  while (!IsAllLoaded(P, maxWeight, sum, n)) {
    P++;
  }
  return P;
}

int main() {
  int n, k;
  cin >> n >> k;
  int P = Calc(n);
  cout << P << endl;
  return 0;
}