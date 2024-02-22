#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    int ans = 0;
    string now = "", next;
    for (int i = 0; i < n; ++i) {
      cin >> next;
      int nowCode = 0, nextCode = 0;
      
      // Assign integer codes to strings
      if (now == "lu") nowCode = 1;
      else if (now == "ru") nowCode = 2;
      else if (now == "ld") nowCode = 3;
      else if (now == "rd") nowCode = 4;
      
      if (next == "lu") nextCode = 1;
      else if (next == "ru") nextCode = 2;
      else if (next == "ld") nextCode = 3;
      else if (next == "rd") nextCode = 4;
      
      // Check for pattern match using integer codes
      if ((nowCode == 1 && nextCode == 2) ||
          (nowCode == 2 && nextCode == 1) ||
          (nowCode == 3 && nextCode == 4) ||
          (nowCode == 4 && nextCode == 3)) {
        ans++;
      }
      
      now = next;
    }
    cout << ans << endl;
  }
  return 0;
}