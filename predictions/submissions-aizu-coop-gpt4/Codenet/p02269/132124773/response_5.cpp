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
    if (com == 'i')
      Dic[word] = true;
    else {
      if (Dic[word])
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }
  return 0;
}