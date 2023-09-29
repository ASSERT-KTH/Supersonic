#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool check(const vector<int> &N, int k, int w) {
  int i = 0;
  for (int j = 0; j < k; ++j) {
    int s = 0;
    while (i < N.size() && s + N[i] <= w) {
      s += N[i];
      ++i;
    }
    if (i == N.size())
      return true;
  }
  return false;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> N(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &N[i]);
  }
  int left = *max_element(N.begin(), N.end());
  int right = 1000000000;
  while (left < right) {
    int mid = (left + right) / 2;
    if (check(N, k, mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  printf("%d\n", right);
  return 0;
}