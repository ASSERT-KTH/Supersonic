#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, bool> dnaSequences;

int main() {
  int numOfCom;
  cin >> numOfCom;
  string com, word;

  while (numOfCom--) {
    cin >> com >> word;
    if (com[0] == 'i') {
      dnaSequences[word] = true;
    } else {
      if (dnaSequences[word]) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }

  return 0;
}