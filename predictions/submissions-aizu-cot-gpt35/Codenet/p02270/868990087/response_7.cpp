#include <iostream>
using namespace std;

size_t check(unsigned int* N, size_t n, unsigned int k, unsigned int w) {
  unsigned int* current = N;
  unsigned int remaining = w;

  for (unsigned int j = 0; j < k; ++j) {
    unsigned int s = 0;
    while (s + *current <= remaining) {
      s += *current;
      ++current;
      if (current == N + n)
        return n;
    }
  }
  return current - N;
}

int main() {
  unsigned int MAX_W = 1000000000;
  size_t n, k;
  cin >> n >> k;
  unsigned int N[n];
  for (size_t i = 0; i < n; ++i) {
    cin >> N[i];
  }
  unsigned int right = MAX_W;

  while (left <= right) {
    unsigned int mid = (left + right) / 2;
    size_t result = check(N, n, k, mid);
    if (result == n) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << right + 1 << endl;
  return 0;
}