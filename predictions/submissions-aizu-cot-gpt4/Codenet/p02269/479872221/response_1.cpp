#include <iostream>
#include <string.h>
#include <string>
#define M 1020001
#define L 14
char H[M][L];

int getnum(char ch) {
  switch(ch) {
    case 'A': return 1;
    case 'C': return 2;
    case 'G': return 3;
    case 'T': return 4;
  }
  return 0;
}

long long getkey(char word[]) {
  int sum = 0, p = 1, i;
  for (i = 0; word[i]; i++) {
    sum += p * getnum(word[i]);
    p *= 5;
  }
  return sum;
}

int h1(int k) { return k % M; }
int h2(int k) { return 1 + (k % (M - 1)); }

int insert(char str[]) {
  int key = getkey(str);
  int h1_val = h1(key);
  int h2_val = h2(key);
  int h = h1_val;
  int i = 0;
  while (strcmp(H[h], str) && H[h][0] != '\0') {
    h = (h1_val + i * h2_val) % M;
    i++;
  }
  if (H[h][0] == '\0') {
    strcpy(H[h], str);
    return 1;
  }
  return 0;
}

int find(char str[]) {
  int key = getkey(str);
  int h1_val = h1(key);
  int h2_val = h2(key);
  int h = h1_val;
  int i = 0;
  while (strcmp(H[h], str) && H[h][0] != '\0') {
    h = (h1_val + i * h2_val) % M;
    i++;
  }
  return H[h][0] != '\0';
}

int main() {
  char com[9], word[14];
  int NumOfCom;
  std::cin >> NumOfCom;
  for (int i = 0; i < M; i++)
    H[i][L] = '\0';
  while (NumOfCom--) {
    std::cin >> com >> word;
    if (com[0] == 'i') {
      insert(word);
    } else {
      std::cout << (find(word) ? "yes" : "no") << std::endl;
    }
  };
  return 0;
}