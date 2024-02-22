#include <bits/stdc++.h>
using namespace std;
#define r(i, n) for (int i = 0; i < n; i++)
#define s(c) static_cast<int>((c).size())

int main() {
  std::ios::sync_with_stdio(false); // Speed up cin and cout operations.
  int n;
  scanf("%d", &n);
  int min = 2000000, t, A[10001]{};
  r(i, n) {
    scanf("%d", &t);
    if (t < min)
      min = t;
    A[t]++;
  }

  printf("%d", min); // Use printf instead of cout.
  for (int i = min; i < 10001; i++) {
    r(j, A[i]) { printf(" %d", i); } // Use printf instead of cout.
  }
  printf("\n"); // Use printf instead of cout.
  return 0;
}