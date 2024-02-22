#include <iostream>
#define M 1020001
#define L 14

char H[M][L];
char empty[M] = {0};

int numLookup[128] = {
    0, 1, 2, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // Q, R, S, T, U, V, W, X, Y, Z, [ , \, ], ^
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // `, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // p, q, r, s, t, u, v, w, x, y, z, { , |, }, ~
};

long long getkey(const char word[]) {
  long long sum = 0;
  for (int i = 0; word[i]; i++) {
    sum = sum * 5 + numLookup[word[i]];
  }
  return sum;
}

int h1(int k) { return k % M; }
int h2(int k) { return 1 + (k % (M - 1)); }

int insert(const char str[]) {
  long long key = getkey(str);
  for (int i = 0;; i++) {
    int h = (h1(key) + i * h2(key)) % M;
    if (!strcmp(H[h], str)) {
      return 0;
    }
    if (empty[h]) {
      strcpy(H[h], str);
      empty[h] = 1;
      return 1;
    }
  }
  return 0;
}

int find(const char str[]) {
  long long key = getkey(str);
  for (int i = 0;; i++) {
    int h = (h1(key) + i * h2(key)) % M;
    if (!strcmp(H[h], str)) {
      return 1;
    }
    if (empty[h]) {
      return 0;
    }
  }
  return 0;
}

int main() {
  char com[9], word[14];
  int NumOfCom;
  std::cin >> NumOfCom;

  memset(empty, 0, sizeof(empty));

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