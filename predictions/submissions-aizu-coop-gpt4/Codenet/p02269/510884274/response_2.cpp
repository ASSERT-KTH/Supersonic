#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int n;
string ins, s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  unordered_set<string> chk;
  cin >> n;
  while (n--) {
    cin >> ins >> s;
    if (ins[0] == 'i') {
      chk.insert(s);
    } else {
      cout << (chk.find(s) != chk.end() ? "yes" : "no") << endl;
    }
  }
  return 0;
}