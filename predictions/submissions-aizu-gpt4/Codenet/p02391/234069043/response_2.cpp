#include <cstdio>
using namespace std;

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  const char* msg[3] = {"a > b\n", "a == b\n", "a < b\n"};
  printf("%s", msg[(a < b) + (a == b)]);
  return 0;
}