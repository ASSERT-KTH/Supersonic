#include <stdio.h>
#include <unordered_map>

int main() {
  int b, d = 0;
  std::unordered_map<int, int> counts;
  
  scanf("%d", &b);
  for (int i = 0; i < b; i++) {
    int num;
    scanf("%d", &num);
    counts[num]++;
  }
  
  scanf("%d", &b);
  for (int i = 0; i < b; i++) {
    int num;
    scanf("%d", &num);
    d += counts[num];
  }
  
  printf("%d\n", d);
  return 0;
}