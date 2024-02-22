#include <iostream>
#include <cstring>
using namespace std;

int main() {
  unsigned int n;
  while (cin >> n, n) {
    unsigned int ans = 0;
    string now = "", next;
    for (size_t i = 0; i < n; ++i) {
      cin >> next;
      int now_int = 0, next_int = 0;
      if (now == "lu") now_int = 1;
      else if (now == "ru") now_int = 2;
      else if (now == "ld") now_int = 3;
      else if (now == "rd") now_int = 4;
      
      if (next == "lu") next_int = 1;
      else if (next == "ru") next_int = 2;
      else if (next == "ld") next_int = 3;
      else if (next == "rd") next_int = 4;
      
      if (now_int && next_int && now_int != next_int)
        ans++;
      
      now = next;
    }
    cout << ans << endl;
  }
  return 0;
}