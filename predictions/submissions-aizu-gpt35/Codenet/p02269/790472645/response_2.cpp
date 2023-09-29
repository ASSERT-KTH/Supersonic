#include <cstdio>
#include <iostream>
#include <unordered_map>
#define REP(i, a, b) for (i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
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
ull dic_op(char str[14]) {
  ull j;
  ull f = 1;
  ull g = 0;
  for (j = 0;; j++) {
    if (str[j] == 'A')
      g += f * 1;
    else if (str[j] == 'C')
      g += f * 2;
    else if (str[j] == 'G')
      g += f * 3;
    else if (str[j] == 'T')
      g += f * 4;
    else
      break;
    f *= 5;
  }
  return g;
}
int main() {
  ull i, j, k, l;
  ull n;
  static char dic[90000000];
  char opstr[7];
  char str[13];
  unordered_map<ull, bool> m;
  cin >> n;
  for (i = 0; i < n; i++) {
    scanf("%s %s", opstr, str);
    if (opstr[0] == 'i') {
      m[dic_op(str)] = true;
    } else if (opstr[0] == 'f') {
      if (m.find(dic_op(str)) != m.end())
        puts("yes");
      else
        puts("no");
      j++;
    }
  }
  return 0;
}