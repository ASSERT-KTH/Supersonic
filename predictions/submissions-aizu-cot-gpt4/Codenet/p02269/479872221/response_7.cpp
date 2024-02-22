#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, bool> H;

int getnum(char ch) {
  switch(ch) {
    case 'A': return 1;
    case 'C': return 2;
    case 'G': return 3;
    default: return 4;
  }
}

long long getkey(string word) {
  int sum = 0, p = 1;
  for (char c : word) {
    sum = sum + p * getnum(c);
    p = p * 5;
  }
  return sum;
}

bool insert(string str) {
  int key = getkey(str);
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
      cout << (find(word) ? "yes" : "no") << endl;
    }
  }

  return 0;
}