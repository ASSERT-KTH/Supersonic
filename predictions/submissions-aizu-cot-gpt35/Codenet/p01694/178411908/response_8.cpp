#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    int ans = 0;
    string now = "";
    for (int i = 0; i < n; ++i) {
      cin >> now;
      switch (now[0]) {
        case 'l':
          if (now[1] == 'u' && now[2] == 'r') ans++;
          break;
        case 'r':
          if (now[1] == 'u' && now[2] == 'l') ans++;
          break;
        case 'l':
          if (now[1] == 'd' && now[2] == 'r') ans++;
          break;
        case 'r':
          if (now[1] == 'd' && now[2] == 'l') ans++;
          break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}