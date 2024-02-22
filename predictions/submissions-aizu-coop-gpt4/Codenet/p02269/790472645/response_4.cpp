#include <unordered_map>
#include <iostream>
using namespace std;
typedef long long ll;

ll dic_op(char str[14]) {
  static int lookup[] = {0, 1, 0, 2, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 4};
  ll f = 1;
  ll g = 0;
  for (int j = 0; str[j]; j++) {
    g += f * lookup[str[j] - 'A'];
    f *= 5;
  }
  return g;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  unordered_map<ll, bool> dic;
  char opstr[7];
  char str[13];
  cin >> n;
  while (n--) {
    cin >> opstr >> str;
    if (opstr[0] == 'i') {
      dic[dic_op(str)] = true;
    } else if (opstr[0] == 'f') {
      cout << (dic[dic_op(str)] ? "yes\n" : "no\n");
    }
  }
  return 0;
}