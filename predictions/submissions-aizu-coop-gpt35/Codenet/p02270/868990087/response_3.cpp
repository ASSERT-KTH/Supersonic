#include <iostream>
using namespace std;

int check(int N[], int n, int k, int w) {
  int i = 0;
  for (int j = 0; j < k; ++j) {
    int s = 0;
    while (s + N[i] <= w) {
      s += N[i];
      ++i;
      if (i == n)
        return n;
    }
  }
  return i;
}

int main() {
  const int MAX_W = 1000000000;
  int n, k;
  cin >> n >> k;
  int N[n];
  for (int i = 0; i < n; ++i) {
    cin >> N[i];
  }
  int left = 0;
  int right = MAX_W;
  while (left <= right) {
    int mid = (left + right) >> 1;
    if (check(N, n, k, mid) == n) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << left << endl;
  return 0;
}