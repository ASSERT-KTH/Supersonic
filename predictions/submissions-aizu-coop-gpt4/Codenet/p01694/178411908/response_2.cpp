#include <iostream>
#include <string>
#include <unordered_map>

#define rep(i, n) for (int i = 0; i < (int)n; ++i)

using namespace std;

int main() {
  int n;
  
  unordered_map<string, int> dict = {
      {"lu", 0},
      {"ru", 1},
      {"ld", 2},
      {"rd", 3},
  };
  
  while (cin >> n, n) {
    int ans = 0;
    int now = -1, next;
    string input;
    rep(i, n) {
      cin >> input;
      next = dict[input];
      if ((now == 0 && next == 1) || (now == 1 && next == 0) ||
          (now == 2 && next == 3) || (now == 3 && next == 2))
        ans++;
      now = next;
    }
    cout << ans << endl;
  }
  
  return 0;
}