#include <iostream>
#include <unordered_map>
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

int dic_op(const string& str) {
  static unordered_map<char, int> charToInt = {
    {'A', 1},
    {'C', 2},
    {'G', 3},
    {'T', 4}
  };
  int g = 0;
  int f = 1;
  for (char c : str) {
    g += f * charToInt[c];
    f *= 5;
  }
  return g;
}

int main() {
  int i, j, k, l;
  int n;
  long ans = 0;
  unordered_map<int, int> dic;
  string opstr, str;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> opstr >> str;
    if (opstr[0] == 'i') {
      dic[dic_op(str)] = 1;
    } else if (opstr[0] == 'f') {
      if (dic.find(dic_op(str)) != dic.end())
        cout << "yes" << endl;
      else
        cout << "no" << endl;
      j++;
    }
  }
  return 0;
}