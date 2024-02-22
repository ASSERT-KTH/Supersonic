#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int dic_op(char str[14]) {
  int j;
  ull f = 1, g = 0;
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
  unordered_map<ull, bool> dic;
  char opstr[7];
  char str[13];
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%s %s", opstr, str);
    ull op = dic_op(str);
    if (opstr[0] == 'i') {
      dic[op] = true;
    } else if (opstr[0] == 'f') {
      if (dic[op])
        puts("yes");
      else
        puts("no");
    }
  }
  return 0;
}