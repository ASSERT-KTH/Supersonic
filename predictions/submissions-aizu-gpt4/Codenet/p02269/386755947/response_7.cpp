#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, bool> d;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s, str;
  while (n--) {
    cin >> s >> str;
    if (s[0] == 'i')
      d[str] = true;
    else
      cout << (d.count(str) ? "yes\n" : "no\n");
  }
  return 0;
}