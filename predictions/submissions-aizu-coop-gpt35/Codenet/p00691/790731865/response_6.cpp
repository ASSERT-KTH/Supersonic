#include <algorithm>
#include <iostream>
using namespace std;

int nr(int a, int* tb, int size) {
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (tb[mid] <= a) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return tb[right];
}

int main() {
  const int size = 1112;
  int tb[size], N;

  for (int i = 1; i < size; i++) {
    tb[i] = i * i * i;
  }

  while (cin >> N, N) {
    int z3 = N * N * N;
    int ret = z3;

    for (int i = 1; i < N; i++) {
      int i3 = i * i * i;
      int j3 = nr(z3 - i3, tb, size);

      ret = z3 - i3 - j3;
    }

    cout << ret << endl;
  }

  return 0;
}