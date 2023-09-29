#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    int ans = 0;
    string now = "", next;
    for (int i = 0; i < n; ++i) {
      cin >> next;
      if (now == "lu" && next == "ru")
        ++ans;
      else if (now == "ru" && next == "lu")
        ++ans;
      else if (now == "ld" && next == "rd")
        ++ans;
      else if (now == "rd" && next == "ld")
        ++ans;
      now = move(next);
    }
    cout << ans << endl;
  }
  return 0;
}