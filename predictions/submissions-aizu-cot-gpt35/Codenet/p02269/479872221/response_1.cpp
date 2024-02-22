#include <iostream>
#define M 1020001
#define L 14

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
  int sum = 0, p = 1, i;
  for (i = 0; word[i]; i++) {
    sum = sum + p * getnum(word[i]);
    p = p * 5;
  }
  return sum;
}

int h(int k, int i) {
  return (k + i) % M;
}

int insert(char str[]) {
  int key, h_val, i;
  key = getkey(str);
  for (i = 0;; i++) {
    h_val = h(key, i);
    if (H[h_val][0] == '\0') {
      strcpy(H[h_val], str);
      return 1;
    } else if (strcmp(H[h_val], str) == 0) {
      return 0;
    }
  }
}

int find(char str[]) {
  int key, h_val, i;
  key = getkey(str);
  for (i = 0;; i++) {
    h_val = h(key, i);
    if (H[h_val][0] == '\0') {
      return 0;
    } else if (strcmp(H[h_val], str) == 0) {
      return 1;
    }
  }
}

int main() {
  char com[9], word[14];
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