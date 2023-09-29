#include <cstdio>
#include <iostream>
#include <unordered_set>
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
  int i, j, k, l;
  int n;
  long ans = 0;
  unordered_set<int> dic;
  char opstr[7];
  char str[13];
  cin >> n;
  for (i = 0; i < n; i++) {
    scanf("%s %s", opstr, str);
    if (opstr[0] == 'i') {
      dic.insert(dic_op(str));
    } else if (opstr[0] == 'f') {
      if (dic.count(dic_op(str)) > 0)
        puts("yes");
      else
        puts("no");
      j++;
    }
  }
  return 0;
}