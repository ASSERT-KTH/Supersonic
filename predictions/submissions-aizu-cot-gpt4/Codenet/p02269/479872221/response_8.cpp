#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, bool> hashTable;

void insert(string str) {
  hashTable[str] = true;
}

bool find(string str) {
  if (hashTable.find(str) != hashTable.end()) {
    return true;
  }
  return false;
}

int main() {
  string com, word;
  int NumOfCom;
  cin >> NumOfCom;
  while (NumOfCom--) {
    cin >> com >> word;
    if (com[0] == 'i') {
      insert(word);
    } else {
      if (find(word)) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  };
  return 0;
}