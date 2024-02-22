#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
  cin.tie(nullptr);
  int n;
  while (cin >> n, n) {
    int ans = 0;
    string now = "", next;
    unordered_map<string, int> stringToInt = {{"lu", 1}, {"ru", 2}, {"ld", 3}, {"rd", 4}};
    for (int i = 0; i < n; ++i) {
      cin >> next;
      if (stringToInt[now] + stringToInt[next] == 3 || stringToInt[now] + stringToInt[next] == 7)
        ans++;
      now = next;
    }
    cout << ans << '\n';
  }
  return 0;
}