#include <iostream>
#include <unordered_map>
#define MOD1 1000000007;
#define MOD2 1000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
ull pow(ull x, ull n) {
  ull res = 1;
  while (n > 0) {
    if (n & 1)
      res = res * x;
    x = x * x;
    n >>= 1;
  }
  return res;
}
int dic_op(const string& str) {
  ll f = 1;
  ll g = 0;
  for (char c : str) {
    if (c == 'A')
      g += f * 1;
    else if (c == 'C')
      g += f * 2;
    else if (c == 'G')
      g += f * 3;
    else if (c == 'T')
      g += f * 4;
    f *= 5;
  }
  return g;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  unordered_map<int, bool> dic;
  string opstr, str;
  for (int i = 0; i < n; i++) {
    cin >> opstr >> str;
    if (opstr[0] == 'i') {
      dic[dic_op(str)] = true;
    } else if (opstr[0] == 'f') {
      if (dic[dic_op(str)])
        cout << "yes\n";
      else
        cout << "no\n";
    }
  }
  return 0;
}