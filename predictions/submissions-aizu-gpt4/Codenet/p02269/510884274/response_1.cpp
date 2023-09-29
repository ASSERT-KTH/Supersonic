#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string, bool> chk;
int n;
string ins, s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); // for more optimization
  cin >> n;
  while (n--) {
    cin >> ins >> s;
    if (ins[0] == 'i') {
      chk[s] = true;
    } else {
      cout << (chk.count(s) ? "yes" : "no") << endl;
    }
  }
  return 0;
}