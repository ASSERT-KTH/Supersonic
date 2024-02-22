#include <iostream>
#include <vector>
using namespace std;

bool check(const vector<int>& N, int n, int k, int w) {
  int s = 0;
  int i = 0;
  for (int j = 0; j < k; ++j) {
    while (i < n && s + N[i] <= w) {
      s += N[i];
      ++i;
    }
    if (i == n)
      return true;
    s = 0;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int MAX_W = 1000000000;
  int n, k;
  cin >> n >> k;
  vector<int> N(n);
  for (int i = 0; i < n; ++i) {
    cin >> N[i];
  }
  int left = 0;
  int right = MAX_W;
  while (left < right) {
    int mid = (left + right) / 2;
    if (check(N, n, k, mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  cout << right << '\n';
  return 0;
}