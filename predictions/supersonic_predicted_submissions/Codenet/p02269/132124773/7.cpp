#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<string, bool> Dic;
  string com, word;
  while (n--) {
    cin >> com >> word;
    if (com[0] == 'i')
      Dic[word] = true;
    else {
      if (Dic[word])
        cout << "YES" << endl;
      else
        cout << "no" << endl;
    }
  }
}
