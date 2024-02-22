#include <iostream>
#include <unordered_map>
using namespace std;

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
  int i;
  int n;
  unordered_map<int, bool> dic;
  char opstr[7];
  char str[13];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> opstr >> str;
    if (opstr[0] == 'i') {
      dic[dic_op(str)] = true;
    } else if (opstr[0] == 'f') {
      if (dic[dic_op(str)])
        cout << "yes\n";
      else
        cout << "no\n";
    }
  }
  return 0;
}