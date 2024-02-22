#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  unordered_map<string, int> str_to_int = {{"lu", 0}, {"ru", 1}, {"ld", 2}, {"rd", 3}};
  int n;
  while (cin >> n, n) {
    int ans = 0;
    int now = -1, next;
    string temp;
    for (int i = 0; i < n; ++i) {
      cin >> temp;
      next = str_to_int[temp];
      if ((now == 0 && next == 1) || (now == 1 && next == 0) ||
          (now == 2 && next == 3) || (now == 3 && next == 2))
        ans++;
      now = next;
    }
    cout << ans << '\n';
  }
  return 0;
}