#include <iostream>
#include <cstring>
#define M 1020001
#define L 14
using namespace std;

char H[M][L];
int char_to_num[] = {0, 1, 2, 3, 4}; // A=1, C=2, G=3, T=4

long long getkey(char word[]) {
  int sum = 0, p = 1, i;
  for (i = 0; word[i]; i++) {
    sum += p * char_to_num[word[i]-'A'];
    p *= 5;
  }
  return sum;
}
int h1(int k) { return k % M; }
int h2(int k) { return 1 + (k % (M - 1)); }

int insert(char str[]) {
  int key = getkey(str);
  for (int i = 0;; i++) {
    int h = (h1(key) + i * h2(key)) % M;
    if (H[h][0] == '\0') { // replace strlen with direct character check
        strcpy(H[h], str);
        return 1;
    }
    if (strcmp(H[h], str) == 0) { // 0 means the strings are equal
      return 0;
    }
  }
}

int find(char str[]) {
  int key = getkey(str);
  for (int i = 0;; i++) {
    int h = (h1(key) + i * h2(key)) % M;
    if (H[h][0] == '\0') { // replace strlen with direct character check
        return 0;
    }
    if (strcmp(H[h], str) == 0) { // 0 means the strings are equal
      return 1;
    }
  }
}

int main() {
  char com[9], word[14];
  int NumOfCom;
  cin >> NumOfCom;
  for (int i = 0; i < M; i++)
    H[i][L] = '\0';
  while (NumOfCom--) {
    cin >> com >> word;
    if (com[0] == 'i') {
      insert(word);
    } else {
      cout << (find(word) ? "yes" : "no") << endl;
    }
  };
  return 0;
}