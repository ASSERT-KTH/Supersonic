#include <cstdio>
#include <bitset>
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
      res *= x;
    x *= x;
    n >>= 1;
  }
  return res;
}
int dic_op(char str[14]) {
  int j;
  long long f = 1;
  long long g = 0;
  for (j = 0;; j++) {
    switch(str[j]){
      case 'A':
        g += f; break;
      case 'C':
        g += f * 2; break;
      case 'G':
        g += f * 3; break;
      case 'T':
        g += f * 4; break;
      default: return g;
    }
    f *= 5;
  }
  return g;
}
int main() {
  int i, j, k, l;
  int n;
  long ans = 0;
  static bitset<90000000> dic;
  char opstr[7];
  char str[13];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s %s", opstr, str);
    if (opstr[0] == 'i') {
      dic.set(dic_op(str));
    } else if (opstr[0] == 'f') {
      if (dic.test(dic_op(str)))
        printf("yes\n");
      else
        printf("no\n");
      j++;
    }
  }
  return 0;
}