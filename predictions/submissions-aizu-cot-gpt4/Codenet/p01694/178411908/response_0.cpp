#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
  unordered_map<string, int> dir = {{"lu", 0}, {"ru", 1}, {"ld", 2}, {"rd", 3}};
  int n;
  while (cin >> n, n) {
    int ans = 0;
    int now = -1, next;
    string str;
    for (int i = 0; i < n; ++i) {
      cin >> str;
      next = dir[str];
      if ((now == 0 && next == 1) || (now == 1 && next == 0) || 
          (now == 2 && next == 3) || (now == 3 && next == 2))
        ans++;
      now = next;
    }
    cout << ans << endl;
  }
  return 0;
}