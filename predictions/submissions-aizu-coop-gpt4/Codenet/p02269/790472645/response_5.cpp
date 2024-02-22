#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;

ll dic_op(char str[14]) {
  ll f = 1;
  ll g = 0;
  for (int j = 0;; j++) {
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
    f <<= 2; f++;
  }
  return g;
}

int main() {
  int n;
  unordered_map<ll, bool> dic;
  char opstr[7];
  char str[13];
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%s %s", opstr, str);
    if (opstr[0] == 'i') {
      dic[dic_op(str)] = true;
    } else if (opstr[0] == 'f') {
      if (dic[dic_op(str)])
        puts("yes");
      else
        puts("no");
    }
  }
  return 0;
}