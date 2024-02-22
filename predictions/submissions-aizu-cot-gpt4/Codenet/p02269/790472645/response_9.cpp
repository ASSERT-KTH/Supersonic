#include <cstdio>
#include <iostream>
#define REP(i, a, b) for (i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
#define MOD1 1000000007;
#define MOD2 1000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dic_op(char str[14]) {
  int j;
  long long f = 1;
  long long g = 0;
  for (j = 0;; j++) {
    switch (str[j]) {
      case 'A':
        g += f;
        break;
      case 'C':
        g += f * 2;
        break;
      case 'G':
        g += f * 3;
        break;
      case 'T':
        g += f * 4;
        break;
      default:
        return g;
    }
    f *= 5;
  }
}

int main() {
  int i, k, l;
  int n;
  long ans = 0;
  static char dic[90000000];
  char opstr[7];
  char str[13];
  cin >> n;
  for (i = 0; i < n; i++) {
    scanf("%s %s", opstr, str);
    if (opstr[0] == 'i') {
      dic[dic_op(str)] = 1;
    } else if (opstr[0] == 'f') {
      if (dic[dic_op(str)])
        puts("yes");
      else
        puts("no");
    }
  }
  return 0;
}