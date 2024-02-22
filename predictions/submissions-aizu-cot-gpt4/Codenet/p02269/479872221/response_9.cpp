#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

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
  for (int i = 0; word[i]; i++) {
    sum += p * getnum(word[i]);
    p *= 5;
  }
  return sum;
}

unordered_map<long long, string> dictionary;

void insert(string str) {
  long long key = getkey(str);
  dictionary[key] = str;
}

bool find(string str) {
  long long key = getkey(str);
  if (dictionary.find(key) != dictionary.end()) {
    return dictionary[key] == str;
  }
  return false;
}

int main() {
  string com, word;
  int NumOfCom;
  cin >> NumOfCom;
  while (NumOfCom) {
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
    NumOfCom--;
  };
  return 0;
}