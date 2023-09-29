#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

unsigned long long pow5[14] = {1};
unordered_set<unsigned long long> dic;

inline unsigned long long dic_op(const string& str) {
  unsigned long long g = 0;
  for (char ch : str) {
    switch (ch) {
      case 'A': break;
      case 'C': g += pow5[&ch - &str[0]] * 2; break;
      case 'G': g += pow5[&ch - &str[0]] * 3; break;
      case 'T': g += pow5[&ch - &str[0]] * 4; break;
    }
  }
  return g;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 1; i < 14; ++i) {
    pow5[i] = pow5[i - 1] * 5;
  }

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string opstr, str;
    cin >> opstr >> str;

    if (opstr[0] == 'i') {
      dic.insert(dic_op(str));
    } else if (opstr[0] == 'f') {
      cout << (dic.count(dic_op(str)) ? "yes\n" : "no\n");
    }
  }

  return 0;
}