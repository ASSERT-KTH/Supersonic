#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_set<string> Dic;
  string com, word;
  while (n--) {
    cin >> com >> word;
    switch (com[0]) {
      case 'i':
        Dic.insert(word);
        break;
      default:
        if (Dic.find(word) != Dic.end())
          cout << "yes" << endl;
        else
          cout << "no" << endl;
        break;
    }
  }
}