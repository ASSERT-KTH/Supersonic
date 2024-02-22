#include <iostream>
using namespace std;

int* Input(const int n) {
  int* W = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> W[i];
  }
  return W;
}

bool IsAllLoaded(int P, int* W, int n, int k) {
  int currSum = 0;
  int trips = 0;
  for (int i = 0; i < n; i++) {
    if (W[i] > P) {
      return false;
    }
    currSum += W[i];
    if (currSum > P) {
      trips++;
      currSum = W[i];
    }
  }
  trips++;
  return trips <= k;
}

int Calc(int* W, int n, int k) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += W[i];
  }
  int left = 1;
  int right = sum;
  int result = sum;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (IsAllLoaded(mid, W, n, k)) {
      result = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return result;
}

int main() {
  int n, k;
  cin >> n >> k;
  int* W = Input(n);
  int P = Calc(W, n, k);
  cout << P << endl;
  delete[] W;
  return 0;
}