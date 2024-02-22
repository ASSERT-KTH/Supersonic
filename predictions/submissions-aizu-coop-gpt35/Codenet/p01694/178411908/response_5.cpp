#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    int ans = 0;
    string now = "", next;
    int nowCode = -1, nextCode;
    for (int i = 0; i < n; ++i) {
      cin >> next;
      if (nowCode == 0 && nextCode == 1)
        ans++;
      else if (nowCode == 1 && nextCode == 0)
        ans++;
      else if (nowCode == 2 && nextCode == 3)
        ans++;
      else if (nowCode == 3 && nextCode == 2)
        ans++;
      now = next;
      if (now == "lu")
        nowCode = 0;
      else if (now == "ru")
        nowCode = 1;
      else if (now == "ld")
        nowCode = 2;
      else if (now == "rd")
        nowCode = 3;
    }
    cout << ans << endl;
  }
  return 0;
}