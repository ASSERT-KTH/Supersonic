#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    int ans = 0;
    char now = '\0', next;
    map<pair<char, char>, int> count;

    for (int i = 0; i < n; ++i) {
      cin >> next;
      if (now != '\0') {
        count[{now, next}]++;
        count[{next, now}]++;
      }
      now = next;
    }

    ans += count[{'l', 'r'}];
    ans += count[{'r', 'l'}];
    ans += count[{'l', 'd'}];
    ans += count[{'d', 'l'}];
    
    cout << ans << endl;
  }
  return 0;
}