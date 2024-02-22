#include <iostream>
#include <cstring>

const int M = 1020001;
const int L = 14;

char H[M][L];

int getnum(char ch) {
  if (ch == 'A') {
    return 1;
  } else if (ch == 'C') {
    return 2;
  } else if (ch == 'G') {
    return 3;
  } else {
    return 4;
  }
}

long long getkey(char word[]) {
  static const int powers[] = {1, 5, 25, 125, 625};
  long long sum = 0;
  for (int i = 0; word[i]; i++) {
    sum += powers[i] * getnum(word[i]);
  }
  return sum;
}

int h1(int k) {
  return k & (M - 1);
}

int h2(int k) {
  return 1 + (k & (M - 2));
}

void insert(char str[]) {
  int key = getkey(str);
  int h, i = 0;
  do {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0) {
      return;
    } else if (strlen(H[h]) == 0) {
      strcpy(H[h], str);
      return;
    }
    i++;
  } while (true);
}

bool find(char str[]) {
  int key = getkey(str);
  int h, i = 0;
  do {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0) {
      return true;
    } else if (strlen(H[h]) == 0) {
      return false;
    }
    i++;
  } while (true);
}

int main() {
  char com[9], word[L];
  int NumOfCom;
  std::cin >> NumOfCom;
  for (int i = 0; i < M; i++) {
    H[i][0] = '\0';
  }
  while (NumOfCom) {
    std::cin >> com >> word;
    if (com[0] == 'i') {
      insert(word);
    } else {
      if (find(word)) {
        std::cout << "yes" << std::endl;
      } else {
        std::cout << "no" << std::endl;
      }
    }
    NumOfCom--;
  }
  return 0;
}