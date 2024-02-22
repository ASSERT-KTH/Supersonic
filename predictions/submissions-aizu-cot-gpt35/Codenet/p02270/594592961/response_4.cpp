#include <iostream>
using namespace std;

int* Input(const int n) {
  int* W = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> W[i];
  }
  return W;
}

bool IsAllLoaded(int P, int* W, int n) {
  int CurrentSum = 0;
  for (int i = 0; i < n; i++) {
    if (W[i] > P) {
      return false;
    }
    if (CurrentSum + W[i] > P) {
      CurrentSum = 0;
    }
    CurrentSum += W[i];
  }
  return true;
}

int Calc(int* W, int n, int k) {
  int Sum = 0;
  for (int i = 0; i < n; i++) {
    Sum += W[i];
  }
  int low = (Sum + k - 1) / k;
  int high = Sum;
  int result = high;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (IsAllLoaded(mid, W, n)) {
      result = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
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