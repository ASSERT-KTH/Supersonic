#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    int ans = 0;
    string now = "", next;
    for (int i = 0; i < n; ++i) {
      getline(cin, next);
      bool patternMatched = false;
      if ((now == "lu" && next == "ru") || (now == "ru" && next == "lu") ||
          (now == "ld" && next == "rd") || (now == "rd" && next == "ld")) {
        patternMatched = true;
      }
      if (patternMatched) {
        ans++;
      }
      now = next;
    }
    cout << ans << endl;
  }
  return 0;
}