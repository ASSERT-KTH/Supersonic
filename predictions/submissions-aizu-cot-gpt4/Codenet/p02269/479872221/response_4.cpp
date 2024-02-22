#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#define M 1020001
#define L 14
char H[M][L] = {""};

int getnum(char ch) {
  switch(ch) {
    case 'A': return 1;
    case 'C': return 2;
    case 'G': return 3;
    default: return 4;
  }
}

long long getkey(char word[]) {
  return std::accumulate(word, word+strlen(word), 0, [](int sum, char ch) {
    return sum * 5 + getnum(ch);
  });
}

int h(int i, int k) { 
  return (k % M + i * (1 + k % (M - 1))) % M; 
}

int find_insert(char str[], bool insert) {
  int key = getkey(str), i = 0, h;

  while(true) {
    h = h(i++, key);
    if (strcmp(H[h], str)) {
      if (strlen(H[h]) == 0) {
        if(insert) std::copy(str, str+strlen(str)+1, H[h]);
        return insert;
      }
    } else {
      return !insert;
    }
  }
}

int main() {
  char com[9], word[14];
  int NumOfCom;
  std::cin >> NumOfCom;
  while (NumOfCom--) {
    std::cin >> com >> word;
    if (com[0] == 'i') {
      find_insert(word, true);
    } else {
      std::cout << (find_insert(word, false) ? "yes" : "no") << std::endl;
    }
  }
  return 0;
}