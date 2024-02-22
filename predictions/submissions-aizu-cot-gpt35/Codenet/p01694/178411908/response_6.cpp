#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  while (scanf("%d", &n), n) {
    int ans = 0;
    string now, next;
    cin >> now;
    for (int i = 1; i < n; ++i) {
      cin >> next;
      switch (now[0]) {
        case 'l':
          if (next[0] == 'r') ans++;
          break;
        case 'r':
          if (next[0] == 'l') ans++;
          break;
        case 'd':
          if (next[0] == 'u') ans++;
          break;
        case 'u':
          if (next[0] == 'd') ans++;
          break;
      }
      now = next;
    }
    printf("%d\n", ans);
  }
  return 0;
}