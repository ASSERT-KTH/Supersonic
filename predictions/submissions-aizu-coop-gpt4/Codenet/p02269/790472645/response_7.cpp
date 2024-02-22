#include <iostream>
#include <unordered_map>
using namespace std;
typedef unsigned long long ull;

unordered_map<string, int> memo;

ull dic_op(char str[14]) {
  if (memo.find(str) != memo.end()) return memo[str];
  
  ull f = 1;
  ull g = 0;
  for (int j = 0; ; j++) {
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
    f <<= 1; 
  }
  memo[str] = g;
  return g;
}

int main() {
  int n;
  unordered_map<ull, bool> dic;
  char opstr[7];
  char str[13];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> opstr >> str;
    if (opstr[0] == 'i') {
      dic[dic_op(str)] = true;
    } else if (opstr[0] == 'f') {
      if (dic[dic_op(str)])
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }
  return 0;
}