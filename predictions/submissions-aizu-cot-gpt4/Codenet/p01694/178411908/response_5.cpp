#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n, n) {
    int ans = 0;
    string now;
    char last_char = ' ';
    for (int i = 0; i < n; ++i) {
      cin >> now;
      if ((last_char == 'u' && now == "ru") || (last_char == 'r' && now == "lu") ||
          (last_char == 'd' && now == "rd") || (last_char == 'd' && now == "ld"))
        ans++;
      last_char = now[1];
    }
    cout << ans << endl;
  }
  return 0;
}