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
    int right = n - 1; // fix 1: set right index to n-1
    int mid = (right + left) / 2;
    while (left <= right) { // fix 2: change while condition to left <= right
      if (T > S[mid]) {
        left = mid + 1;
      } else if (T < S[mid]) {
        right = mid - 1; // fix 3: set right index to mid-1
      } else {
        ++cnt;
        break;
      }
      mid = (right + left) / 2;
    }
  }
  cout << cnt << endl;
  return 0;
}