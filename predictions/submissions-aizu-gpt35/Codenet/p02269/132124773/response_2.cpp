#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main() {
  int n;
  cin >> n;
  unordered_map<string, bool> Dic;
  string com, word;
  while (n--) {
    cin >> com >> word;
    if (com[0] == 'i')
      Dic[word] = true;
    else {
      if (Dic.find(word) != Dic.end() && Dic[word])
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }
}