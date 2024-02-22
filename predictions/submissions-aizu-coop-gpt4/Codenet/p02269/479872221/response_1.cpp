#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

#define M 1020001
#define L 14

unordered_map<string, bool> H;

int getnum(char ch) {
  switch(ch){
    case 'A': return 1;
    case 'C': return 2;
    case 'G': return 3;
    case 'T': return 4;
    default: return 0;
  }
}

long long getkey(string word) {
  int sum = 0, p = 1;
  for (char ch: word) {
    sum += p * getnum(ch);
    p *= 5;
  }
  return sum;
}

bool insert(string str) {
  int key = getkey(str);
  if(H.find(str) != H.end()){
      return false;
  }else{
      H[str] = true;
      return true;
  }
}

bool find(string str) {
  if(H.find(str) != H.end()){
      return true;
  }else{
      return false;
  }
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