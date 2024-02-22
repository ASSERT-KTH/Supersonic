#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  
  unordered_map<string, bool> Dic;
  Dic.reserve(n);
  
  string com, word;
  while (n--) {
    cin >> com >> word;
    if (com[0] == 'i')
      Dic[word] = true;
    else {
      if (Dic[word])
        cout << "yes\n";
      else
        cout << "no\n";
    }
  }
}