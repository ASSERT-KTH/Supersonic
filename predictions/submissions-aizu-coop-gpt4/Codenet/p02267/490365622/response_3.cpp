#include <stdio.h>
#include <unordered_set>
int main() {
  int n, q, T[500], i, j, cnt = 0;
  std::unordered_set<int> S;
  
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    int temp;
    scanf("%d", &temp);
    S.insert(temp);
  }
  
  scanf("%d", &q);
  
  for (j = 0; j < q; j++) {
    scanf("%d", &T[j]);
    if(S.find(T[j]) != S.end()){
        cnt++;
    }
  }
  
  printf("%d\n", cnt);
  
  return 0;
}