#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int getnum(char ch) {
  if (ch == 'A') return 1;
  else if (ch == 'C') return 2;
  else if (ch == 'G') return 3;
  else return 4;
}

long long getkey(const string& word) {
  int sum = 0, p = 1;
  for (char c : word) {
    sum += p * getnum(c);
    p *= 5;
  }
  return sum;
}

unordered_map<long long, string> hashTable;

void insert(const string& str) {
  long long key = getkey(str);
  hashTable[key] = str;
}

bool find(const string& str) {
  long long key = getkey(str);
  return hashTable.find(key) != hashTable.end();
}

int main() {
  int NumOfCom;
  cin >> NumOfCom;
  
  while (NumOfCom--) {
    string com, word;
    cin >> com >> word;
    
    if (com[0] == 'i') insert(word);
    else if (com[0] == 'f') {
      if (find(word)) cout << "yes" << endl;
      else cout << "no" << endl;
    }
  };
  
  return 0;
}