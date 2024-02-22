#include <cstdio>
#define REP(i, a, b) for (i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
#define MOD1 1000000007;
#define MOD2 1000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll dic_op(char str[14]) {
  int j;
  ll f = 1;
  ll g = 0;
  for (j = 0;; j++) {
    if (str[j] == 'A')
      g += f;
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
  int i, n;
  static char dic[2000000000] = {0};
  char opstr[7];
  char str[13];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s %s", opstr, str);
    if (opstr[0] == 'i') {
      dic[dic_op(str)] = 1;
    } else if (opstr[0] == 'f') {
      if (dic[dic_op(str)] == 1)
        puts("yes");
      else
        puts("no");
    }
  }
  return 0;
}