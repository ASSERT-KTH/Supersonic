#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

typedef long long ll;

ll dic_op(const string& str) {
  ll f = 1;
  ll g = 0;
  for (char c : str) {
    switch (c) {
      case 'A': g += f; break;
      case 'C': g += f * 2; break;
      case 'G': g += f * 3; break;
      case 'T': g += f * 4; break;
    }
    f *= 5;
  }
  return g;
}

int main() {
  int n;
  unordered_map<ll, bool> dic;
  string opstr, str;
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> opstr >> str;
    switch (opstr[0]) {
      case 'i': dic[dic_op(str)] = true; break;
      case 'f': cout << (dic[dic_op(str)] ? "yes" : "no") << endl; break;
    }
  }
  return 0;
}