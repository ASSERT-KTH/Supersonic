#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int* S = new int[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &S[i]);
  }
  sort(S, S + n);
  int q;
  scanf("%d", &q);
  int cnt = 0;
  while (q--) {
    int T;
    scanf("%d", &T);
    if (binary_search(S, S + n, T)) {
      ++cnt;
    }
  }
  printf("%d\n", cnt);
  delete[] S;
  return 0;
}