#include <cstdio>
#include <vector>
#include <algorithm>

#define rep(i, a, b) for (int i = (a); i < (b); i++)

void counting_sort(std::vector<int> &v) {
  int n = v.size(), k = *std::max_element(v.begin(), v.end());
  std::vector<int> cnt(k + 1);
  for (int x : v)
    cnt[x]++;
  int index = 0;
  for (int i = 0; i <= k; i++)
    for (int j = 0; j < cnt[i]; j++)
      v[index++] = i;
}

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> A(n);
  rep(i, 0, n) { scanf("%d", &A[i]); }
  counting_sort(A);
  printf("%d", A[0]);
  rep(i, 1, A.size()) { printf(" %d", A[i]); }
  printf("\n");
  return 0;
}