#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
  unordered_map<string, int> pattern = {
    {"luru", 1},
    {"rulu", 1},
    {"ldrd", 1},
    {"rdld", 1}
  };

  int n;
  while (cin >> n, n) {
    int ans = 0;
    string now = "", next;
    for (int i = 0; i < n; ++i) {
      cin >> next;
      string pair = now + next;
      if (pattern.find(pair) != pattern.end())
        ans++;
      now = next;
    }
    cout << ans << endl;
  }
  return 0;
}