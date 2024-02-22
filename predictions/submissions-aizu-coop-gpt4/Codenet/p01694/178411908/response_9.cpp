#include <iostream>
#include <unordered_map>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

int main() {
  int n;
  unordered_map<string, bool> validPairs = {{"lu ru", true}, {"ru lu", true}, {"ld rd", true}, {"rd ld", true}};
  while (cin >> n, n) {
    int ans = 0;
    string now = "", next, pair;
    for(int i = 0; i < n; ++i) {
      cin >> next;
      pair = now + " " + next;
      if (validPairs[pair])
        ans++;
      now = next;
    }
    cout << ans << endl;
  }
  return 0;
}