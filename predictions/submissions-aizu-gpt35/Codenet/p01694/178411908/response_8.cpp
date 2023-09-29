#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  while (cin >> n, n) {
    int ans = 0;
    string now = "", next;
    cin >> now;
    for (int i = 1; i < n; ++i) {
      cin >> next;
      if ((now == "lu" && next == "ru") || (now == "ru" && next == "lu") || (now == "ld" && next == "rd") || (now == "rd" && next == "ld"))
        ++ans;
      now = next;
    }
    cout << ans << endl;
  }
  return 0;
}