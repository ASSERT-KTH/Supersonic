#include <iostream>
using namespace std;

int check(int N, int n, int k, int w) {
  int i = 0;
  for (int j = 0; j < k; ++j) {
    int s = 0;
    while (s + N <= w) {
      s += N;
      ++i;
      if (i == n)
        return n;
    }
  }
  return i;
}

int main() {
  int MAX_W = 1000000000;
  int n, k;
  cin >> n >> k;
  int N = 0;
  for (int i = 0; i < n; ++i) {
    int weight;
    cin >> weight;
    N = max(N, weight);
  }
  int right = N * k;
  while (true) {
    if (check(N, n, k, right) == n) {
      break;
    }
    right--;
  }
  cout << right << endl;
  return 0;
}