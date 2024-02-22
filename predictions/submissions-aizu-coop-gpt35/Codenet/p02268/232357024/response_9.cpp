#include <cstdio>
#include <iostream>
using namespace std;

const int max_n = 1000000; // Maximum possible value of n

int main() {
  int n;
  scanf("%d", &n);
  int S[max_n];
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
    int mid = (right + left) / 2; // Compute mid before the loop
    while (left < right) {
      if (T > S[mid]) {
        left = mid + 1;
      } else if (T < S[mid]) {
        right = mid;
      } else {
        ++cnt;
        break;
      }
      mid = (right + left) / 2; // Update mid after updating left or right
    }
  }
  cout << cnt << endl;
  return 0;
}