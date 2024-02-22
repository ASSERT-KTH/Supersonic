#include <iostream>
#include <cstring>
using namespace std;

const int TABLE_SIZE = 1020001;
const int WORD_LENGTH = 14;

char H[TABLE_SIZE][WORD_LENGTH];
int lengths[TABLE_SIZE] = {0};

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

int h1(int k) {
  return k % TABLE_SIZE;
}

int h2(int k) {
  return 1 + (k % (TABLE_SIZE - 1));
}

int insert(char str[]) {
  int key, h, i;
  key = getkey(str);
  for (i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % TABLE_SIZE;
    if (H[h][0] == '\0') {
      strcpy(H[h], str);
      lengths[h] = strlen(str);
      return 1;
    } else if (strcmp(H[h], str) == 0) {
      return 0;
    }
  }
}

int find(char str[]) {
  int key, h, i;
  key = getkey(str);
  for (i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % TABLE_SIZE;
    if (H[h][0] == '\0') {
      return 0;
    } else if (strcmp(H[h], str) == 0) {
      return 1;
    }
  }
}

int main() {
  char com[9], word[WORD_LENGTH];
  int NumOfCom;
  cin >> NumOfCom;

  // No need to initialize H array

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
  }

  return 0;
}