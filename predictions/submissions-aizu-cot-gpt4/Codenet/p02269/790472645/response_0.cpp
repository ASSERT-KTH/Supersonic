#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;

ll dic_op(char str[14]) {
  ll j;
  ll f = 1;
  ll g = 0;
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  unordered_map<ll, bool> dic;
  char opstr[7];
  char str[13];
  cin >> n;
  for (int i = 0; i < n; i++) {
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