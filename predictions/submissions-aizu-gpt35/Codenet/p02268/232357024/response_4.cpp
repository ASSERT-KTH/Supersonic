#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int *S = new int[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &S[i]);
  }
  int cnt = 0;
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int T;
    scanf("%d", &T);
    int left = 0;
    int right = n-1;
    int mid;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (T > S[mid]) {
        left = mid + 1;
      } else if (T < S[mid]) {
        right = mid - 1;
      } else {
        ++cnt;
        break;
      }
    }
  }
  cout << cnt << endl;
  delete[] S;
  return 0;
}