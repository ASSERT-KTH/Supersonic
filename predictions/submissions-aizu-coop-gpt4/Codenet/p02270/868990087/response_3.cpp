#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int MAX_W = 1000000000;
  int n, k;
  scanf("%d %d", &n, &k);
  int N[n], P[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &N[i]);
    P[i] = (i == 0) ? N[i] : P[i-1] + N[i];
  }
  int left = 0;
  int right = MAX_W;
  while (left < right) {
    int mid = (left + right) / 2;
    int i = lower_bound(P, P+n, mid*k) - P;
    if (i == n || (i > 0 && P[i-1] == mid*k)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  cout << right << endl;
  return 0;
}