#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  unordered_map<string, bool> Dic;
  string com, word;
  com.reserve(100);
  word.reserve(100);
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