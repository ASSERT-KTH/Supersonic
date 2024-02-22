#include <iostream>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull dic_op(char str[14]) {
  ull g = 0;
  ull f = 1;
  for (int j = 0; str[j] != '\0'; j++) {
    switch (str[j]) {
      case 'A': g += f * 1; break;
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
  cin >> n;
  unordered_set<ull> dic;
  char opstr[7];
  char str[13];

  for (int i = 0; i < n; i++) {
    cin >> opstr >> str;
    ull hash = dic_op(str);

    if (opstr[0] == 'i') {
      dic.insert(hash);
    } else if (opstr[0] == 'f') {
      if (dic.count(hash) > 0)
        cout << "yes\n";
      else
        cout << "no\n";
    }
  }

  return 0;
}