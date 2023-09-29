#include <iostream>
using namespace std;
#include <string.h>
#include <string>
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
  return 0;
}
long long getkey(char word[]) {
  int sum = 0, p = 1, i;
  for (i = 0; word[i]; i++) {
    sum = sum + p * getnum(word[i]);
    p = p * 5;
  }
  return sum;
}
int h1(int k) { return k % M; }
int h2(int k) { return 1 + (k % (M - 1)); }
int insert(char str[]) {
  int key, h, i;
  key = getkey(str);
  for (i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str)) {
      if (strlen(H[h]) == 0) {
        strcpy(H[h], str);
        return 1;
      }
    } else {
      return 0;
    }
  }
  return 0;
}
int find(char str[]) {
  int key, h, i;
  key = getkey(str);
  for (i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h]) == 0) {
      if (strlen(H[h]) == 0) {
     