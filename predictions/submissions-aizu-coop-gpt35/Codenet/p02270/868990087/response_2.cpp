#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int check(const vector<int>& N, int n, int k, int w, int& i) {
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
  int MAX_W = 1000000000;
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> N(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &N[i]);
  }
  int left = 0;
  int right = MAX_W;
  int i = 0;
  while (left < right) {
    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;

    int i1 = i;
    int i2 = i;

    int res1 = check(N, n, k, mid1, i1);
    int res2 = check(N, n, k, mid2, i2);

    if (res1 == n) {
      right = mid1;
      i = i1;
    } else if (res2 == n) {
      left = mid2;
      i = i2;
    } else {
      left = mid1 + 1;
    }
  }
  cout << right << endl;
  return 0;
}