#include <iostream>
#include <unordered_map>
using namespace std;

int dic_op(const string& str) {
  int g = 0;
  for (char c : str) {
    g *= 5;
    if (c == 'A')
      g += 1;
    else if (c == 'C')
      g += 2;
    else if (c == 'G')
      g += 3;
    else if (c == 'T')
      g += 4;
    else
      break;
  }
  return g;
}

int main() {
  int n;
  unordered_map<int, int> dic;
  string opstr, str;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> opstr >> str;
    if (opstr == "i") {
      dic[dic_op(str)] = 1;
    } else if (opstr == "f") {
      if (dic.count(dic_op(str)) > 0)
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }
  return 0;
}