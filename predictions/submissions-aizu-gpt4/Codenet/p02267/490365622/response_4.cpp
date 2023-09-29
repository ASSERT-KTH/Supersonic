#include <stdio.h>
#include <unordered_set>

int main() {
  int n, q, i, cnt = 0;
  std::unordered_set<int> S;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    int temp;
    scanf("%d", &temp);
    S.insert(temp);
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    int temp;
    scanf("%d", &temp);
    if (S.find(temp) != S.end())
      cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}