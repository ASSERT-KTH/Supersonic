#include <iostream>
using namespace std;
int main() {
  int n, m, a;
  while (true) {
    scanf("%d %d %d", &n, &m, &a);
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    int amida[1001] = {0};
    for (int i = 0; i < m; i++) {
      int h = 0, p = 0, q = 0;
      scanf("%d %d %d", &h, &p, &q);
      amida[p] = 1;
      amida[q] = 1;
    }
    for (int j = a; j > 0; j--) {
      if (amida[j] == 1)
        a++;
      else if (amida[j - 1] == 1)
        a--;
    }
    printf("%d\n", a);
  }
  return 0;
}