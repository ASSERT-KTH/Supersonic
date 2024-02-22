#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  vector<int> S(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &S[i]);
  }

  int cnt = 0;
  int q;
  scanf("%d", &q);

  while (q--) {
    int T;
    scanf("%d", &T);

    int left = 0;
    int right = n - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (S[mid] == T) {
        ++cnt;
        break;
      } else if (S[mid] < T) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }

  cout << cnt << endl;
  return 0;
}