#include <iostream>
#define MOD1 1000000007;
#define MOD2 1000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dic_op(char str[14]) {
  ll f = 1;
  ll g = 0;
  for (int j = 0;; j++) {
    switch(str[j]){
        case 'A': g += f * 1; break;
        case 'C': g += f * 2; break;
        case 'G': g += f * 3; break;
        case 'T': g += f * 4; break;
        default:  return g;
    }
    f *= 5;
  }
}

int main() {
  int n;
  long ans = 0;
  static char dic[90000000];
  char opstr[7];
  char str[13];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> opstr >> str;
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