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

unordered_map<string, bool> dic;

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
  int i, k, l;
  int n;
  long ans = 0;
  string opstr;
  char str[13];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> opstr >> str;
    if (opstr[0] == 'i') {
      dic[str] = true;
    } else if (opstr[0] == 'f') {
      if (dic[str])
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }
  return 0;
}