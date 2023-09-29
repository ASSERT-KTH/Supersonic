#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, bool> H;

bool insert(string str) {
  if (H.find(str) == H.end()) {
    H[str] = true;
    return true;
  }
  return false;
}

bool find(string str) {
  return H.find(str) != H.end();
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