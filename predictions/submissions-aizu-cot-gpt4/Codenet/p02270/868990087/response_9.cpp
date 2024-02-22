#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int check(vector<int>& N, int n, int k, int w) {
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
    int mid = (left + right) >> 1;
    int checkResult = check(N, n, k, mid);
    if (checkResult == n) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  cout << right << endl;
  return 0;
}