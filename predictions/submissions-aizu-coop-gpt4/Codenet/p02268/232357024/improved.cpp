#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int S[n];
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
    int right = n;
    int mid = (left + right) / 2;
    while (left < right) {
      if (T == S[mid]) {
        cnt++;
        break;
      } else if (T < S[mid]) {
        right = mid;
      } else {
        left = mid + 1;
      }
      mid = (left + right) / 2;
    }
  }
  cout << cnt << endl;
  return 0;
}
