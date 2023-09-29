#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

unordered_set<string> hashTable;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int NumOfCom;
  cin >> NumOfCom;
  string com, word;
  
  while (NumOfCom--) {
    cin >> com >> word;
    if (com[0] == 'i') {
      hashTable.insert(word);
    } else {
      if (hashTable.find(word) != hashTable.end()) {
        cout << "yes" << "\n";
      } else {
        cout << "no" << "\n";
      }
    }
  };
  return 0;
}