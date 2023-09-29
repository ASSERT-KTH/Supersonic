#include <unordered_map>
#include <cstdio>
#include <iostream>
using namespace std;
typedef unsigned long long ull;

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

ull dic_op(const char* str) {
  int j = 0;
  ull f = 1;
  ull g = 0;
  while (true) {
    switch(str[j]) {
      case 'A': g += f * 1; break;
      case 'C': g += f * 2; break;
      case 'G': g += f * 3; break;
      case 'T': g += f * 4; break;
      default: return g;
    }
    f *= 5;
    j++;
  }
  return g;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  char opstr[7];
  char str[13];
  cin >> n;
  unordered_map<ull, bool> dic;

  while(n--) {
    scanf("%s %s", opstr, str);
    ull op = dic_op(str);
    if (opstr[0] == 'i') {
      dic[op] = true;
    } else if (opstr[0] == 'f') {
      puts(dic[op] ? "yes" : "no");
    }
  }
  return 0;
}