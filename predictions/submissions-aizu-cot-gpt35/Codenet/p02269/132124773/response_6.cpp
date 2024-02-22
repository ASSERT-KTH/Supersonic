#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_map<string, bool> Dic;
  Dic.reserve(n); // Preallocate memory for the unordered_map
  string com, word;
  while (n--) {
    cin >> com >> word;
    if (com[0] == 'i')
      Dic[word] = true;
    else {
      if (Dic.count(word) > 0)
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }
}