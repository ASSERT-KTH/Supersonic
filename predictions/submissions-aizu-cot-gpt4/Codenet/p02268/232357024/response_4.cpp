#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int S[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &S[i]);
  }
  sort(S, S+n);
  int cnt = 0;
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int T;
    scanf("%d", &T);
    int left = 0;
    int right = n;
    while (left < right) {
      int mid = (right + left) / 2;
      if (T > S[mid]) {
        left = mid + 1;
      } else if (T < S[mid]) {
        right = mid;
      } else {
        ++cnt;
        break;
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}