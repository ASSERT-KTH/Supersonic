#include <iostream>
int main() {
  int x, y;
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  scanf("%d",&x);
  y = x * x * x;
  printf("%d\n",y);
  return 0;
}