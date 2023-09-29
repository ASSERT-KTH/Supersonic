#include <cstdio>
#include <iostream>
#include <cstring> // added header for memset
using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
#define MOD1 1000000007; // semicolon removed
#define MOD2 1000007

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

int dic_op(char str[14]) {
  int j;
  long long f = 1;
  long long g = 0;
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
  int n;
  static char dic[1 << 25]; // reduce array size
  char opstr[7];
  char str[13];
  cin >> n;
  memset(dic, 0, sizeof(dic)); // initialize array to 0
  int j = 0; // initialize j to 0
  for (int i = 0; i < n; i++) {
    scanf("%s %s", opstr, str);
    if (opstr[0] == 'i') {
      dic[dic_op(str)] = 1;
    } else if (opstr[0] == 'f') {
      if (dic[dic_op(str)] == 1)
        puts("yes");
      else
        puts("no");
      j++;
    }
  }
  return 0;
}