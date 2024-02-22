#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_map<string, bool> Dic;
  char com;
  string word;
  while (n--) {
    cin >> com >> word;
    switch(com) {
      case 'i':
        Dic[word] = true;
        break;
      case 'f':
        if (Dic.find(word) != Dic.end())
          cout << "yes\n";
        else
          cout << "no\n";
        break;
      default:
        break;
    }
  }
}