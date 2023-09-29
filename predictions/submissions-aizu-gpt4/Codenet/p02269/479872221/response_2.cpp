#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
  unordered_set<string> uset;
  int NumOfCom;
  string word, com;
  cin >> NumOfCom;
  while (NumOfCom--) {
    cin >> com >> word;
    if (com[0] == 'i') {
      uset.insert(word);
    } else {
      if (uset.find(word) != uset.end()) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }
  return 0;
}