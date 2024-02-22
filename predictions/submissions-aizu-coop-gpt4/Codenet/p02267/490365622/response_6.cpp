#include <stdio.h>
#include <unordered_set>
using namespace std;

int main() {
  int n, q, temp, cnt = 0;
  unordered_set<int> S;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    S.insert(temp);
  }
  
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &temp);
    if (S.find(temp) != S.end()) cnt++;
  }
  
  printf("%d\n", cnt);
  return 0;
}