#include <iostream>
using namespace std;
int main() {
  int is;
  int h, m, s;
  scanf("%d", &is);
  h = is / 3600;
  is %= 3600;
  m = is / 60;
  is %= 60;
  printf("%d:%d:%d\n", h, m, is);
  return 0;
}