#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_map<string, bool> Dic;
  string com, word, result;
  while (n--) {
    cin >> com >> word;
    if (com[0] == 'i') {
      Dic[word] = true;
    } else {
      if (Dic.find(word) != Dic.end()) {
        result += "yes\n";
      } else {
        result += "no\n";
      }
    }
  }
  cout << result;
  return 0;
}